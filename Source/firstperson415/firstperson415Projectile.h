// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "firstperson415Projectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UNiagaraSystem;

UCLASS(config=Game)
class Afirstperson415Projectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

	// Ball Mesh
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ballMesh;

	// Base Material
	UPROPERTY(EditAnywhere)
	UMaterial* baseMat;

	// Random Color
	UPROPERTY()
	FLinearColor randColor;

	// Projectile Decal Material
	UPROPERTY(EditAnywhere)
	UMaterialInterface* projMat;

	// Dynamic Material Instance
	UPROPERTY()
	UMaterialInstanceDynamic* dmiMat;

	// Niagara Particle System for Color Impact
	UPROPERTY(EditAnywhere)
	UNiagaraSystem* colorP;


public:
	Afirstperson415Projectile();

protected:
	virtual void BeginPlay();

public:
	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
};

