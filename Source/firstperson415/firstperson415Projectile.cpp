// Copyright Epic Games, Inc. All Rights Reserved.

#include "firstperson415Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/SphereComponent.h"
#include "Components/DecalComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "PerlinProcTerrain.h"
#include "GameFramework/Character.h"

Afirstperson415Projectile::Afirstperson415Projectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &Afirstperson415Projectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Create the ball mesh component
	ballMesh = CreateDefaultSubobject<UStaticMeshComponent>("Ball Mesh");

	// Set as root component
	RootComponent = CollisionComp;

	// Attach ball mesh to collision component
	ballMesh->SetupAttachment(CollisionComp);

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void Afirstperson415Projectile::BeginPlay()
{
	// Call the base class
	Super::BeginPlay();

	// Ignore the owner and instigator of the projectile to prevent immediate collision
    if (GetOwner())
    {
        CollisionComp->IgnoreActorWhenMoving(GetOwner(), true);
    }

    if (GetInstigator())
    {
        CollisionComp->IgnoreActorWhenMoving(GetInstigator(), true);
    }

	// Generate random color
	randColor = FLinearColor(UKismetMathLibrary::RandomFloatInRange(0.f, 1.f), UKismetMathLibrary::RandomFloatInRange(0.f, 1.f), UKismetMathLibrary::RandomFloatInRange(0.f, 1.f), 1.f);

	// Create Dynamic Material Instance and set ball mesh material
	dmiMat = UMaterialInstanceDynamic::Create(projMat, this);
	ballMesh->SetMaterial(0, dmiMat);

	// Set Dynamic Material Instance color parameter
	dmiMat->SetVectorParameterValue("ProjColor", randColor);
}

void Afirstperson415Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (!OtherActor || OtherActor == this)
    {
        return;
    }

    // If we hit a physics-simulating object, apply impulse and stop here
    if (OtherComp && OtherComp->IsSimulatingPhysics())
    {
        OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
        Destroy();
        return;
    }

    // Get knockback direction from projectile velocity
    FVector KnockbackDir = GetVelocity().GetSafeNormal();

    // If the hit actor is a character, launch it in the knockback direction
    ACharacter* HitCharacter = Cast<ACharacter>(OtherActor);
    if (HitCharacter)
    {
        FVector LaunchVec = (KnockbackDir * 1500.0f) + FVector(0.f, 0.f, 500.f);
        HitCharacter->LaunchCharacter(LaunchVec, true, true);
    }

    // Apply damage to anything we hit
    UGameplayStatics::ApplyDamage(
        OtherActor,
        1.0f,
        GetInstigatorController(),
        GetOwner(),
        UDamageType::StaticClass()
    );

    // Spawn Niagara Particle System if set
    if (colorP)
    {
        UNiagaraComponent* ParticleComp = UNiagaraFunctionLibrary::SpawnSystemAttached(
            colorP,
            HitComp,
            NAME_None,
            FVector(-20.f, 0.f, 0.f),
            FRotator(0.f),
            EAttachLocation::KeepRelativeOffset,
            true
        );

        if (ParticleComp)
        {
            ParticleComp->SetNiagaraVariableLinearColor(FString("RandomColor"), randColor);
        }

        // Remove ball mesh and disable collision
        if (ballMesh)
        {
            ballMesh->DestroyComponent();
        }

        if (CollisionComp)
        {
            CollisionComp->BodyInstance.SetCollisionProfileName("NoCollision");
        }
    }

    // Random frame number between 0 and 3
    float frameNum = UKismetMathLibrary::RandomFloatInRange(0.f, 3.f);

    // Spawn decal
    UDecalComponent* Decal = UGameplayStatics::SpawnDecalAtLocation(
        GetWorld(),
        baseMat,
        FVector(UKismetMathLibrary::RandomFloatInRange(20.f, 40.f)),
        Hit.Location,
        Hit.Normal.Rotation(),
        0.f
    );

    if (Decal)
    {
        UMaterialInstanceDynamic* MatInstance = Decal->CreateDynamicMaterialInstance();

        if (MatInstance)
        {
            MatInstance->SetVectorParameterValue("Color", randColor);
            MatInstance->SetScalarParameterValue("Frame", frameNum);
        }
    }

    // Check if the hit actor is procedural terrain
    APerlinProcTerrain* procTerrain = Cast<APerlinProcTerrain>(OtherActor);
    if (procTerrain)
    {
        procTerrain->AlterMesh(Hit.Location);
    }

    Destroy();
}