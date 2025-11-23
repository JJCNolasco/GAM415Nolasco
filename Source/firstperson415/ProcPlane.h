// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProcPlane.generated.h"

// Forward declaration
class UProceduralMeshComponent;

UCLASS()
class FIRSTPERSON415_API AProcPlane : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProcPlane();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called after the actor has been created (in editor or during gameplay)
	virtual void PostActorCreated() override;

	// Called after the actor and all its components have been loaded
	virtual void PostLoad() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Procedural Mesh Component
	UPROPERTY(EditAnywhere)
		TArray<FVector> Vertices;

	// Triangles array
	UPROPERTY(EditAnywhere)
		TArray<int> Triangles;

	// UV0 array
	UPROPERTY(EditAnywhere)
		TArray<FVector2D> UV0;

	// Material for the mesh
	UPROPERTY(EditAnywhere)
		UMaterialInterface* PlaneMat;

	// Function to create the mesh
	UFUNCTION()
		void CreateMesh();

private:
	UProceduralMeshComponent* procMesh;


};
