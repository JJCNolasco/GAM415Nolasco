// Fill out your copyright notice in the Description page of Project Settings.


#include "Portal.h"
#include "firstperson415Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APortal::APortal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create components
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	boxComp = CreateDefaultSubobject<UBoxComponent>("Box Comp");
	sceneCapture = CreateDefaultSubobject<USceneCaptureComponent2D>("Capture");
	rootArrow = CreateDefaultSubobject<UArrowComponent>("Root Arrow");

	// Attach components
	RootComponent = boxComp;
	mesh->SetupAttachment(boxComp);
	sceneCapture->SetupAttachment(mesh);
	rootArrow->SetupAttachment(RootComponent);

	// ignore collisions
	mesh->SetCollisionResponseToAllChannels(ECR_Ignore);

}

// Called when the game starts or when spawned
void APortal::BeginPlay()
{
	Super::BeginPlay();

	// Set up box overlap event
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &APortal::OnOverlapBegin);

	// Hide mesh in scene capture
	mesh->SetHiddenInSceneCapture(true);

	// Apply material
	if (mat)
	{
		mesh->SetMaterial(0, mat);
	}
	
}

// Called every frame
void APortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdatePortals();

}

void APortal::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Cast to player character
	Afirstperson415Character* playerChar = Cast<Afirstperson415Character>(OtherActor);

	// Teleport player if not already teleporting
	if (playerChar)
	{
		if (otherPortal)
		{
			if (!playerChar->isTeleporting)
			{
				// Teleport player to other portal location
				playerChar->isTeleporting = true;
				FVector loc = otherPortal->rootArrow->GetComponentLocation();
				playerChar->SetActorLocation(loc);

				// Set timer to reset teleporting bool
				FTimerHandle TimerHandle;
				FTimerDelegate TimerDelegate;
				TimerDelegate.BindUFunction(this, "SetBool", playerChar);
				GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, 1, false);
			}
		}
	}

}

void APortal::SetBool(Afirstperson415Character* playerChar)
{
	// Reset teleporting bool
	playerChar->isTeleporting = false;
}

void APortal::UpdatePortals()
{
	// Get location difference between portals
	FVector Location = this->GetActorLocation() - otherPortal->GetActorLocation();

	// Get player camera location
	FVector camLocation = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetTransformComponent()->GetComponentLocation();

	// Get player camera rotation
	FRotator camRotation = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetTransformComponent()->GetComponentRotation();

	// Calculate combined location
	FVector CombinedLocation = camLocation + Location;

	// Set scene capture location and rotation
	sceneCapture->SetWorldLocationAndRotation(CombinedLocation, camRotation);
}

