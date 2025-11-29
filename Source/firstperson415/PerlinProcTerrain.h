// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PerlinProcTerrain.generated.h"

// Forward declarations
class UProceduralMeshComponent;
class UMaterialInterface;

UCLASS()
class FIRSTPERSON415_API APerlinProcTerrain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APerlinProcTerrain();

	// Size of the terrain in X direction
	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0))
		int XSize = 0;

	// Size of the terrain in Y direction
	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0))
		int YSize = 0;

	// Material for the terrain
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ClampMin = 0))
		float ZMultiplier = 1.0f;

	// Scale of the Perlin noise
	UPROPERTY(EditANywhere, Meta = (ClampMin = 0))
		float NoiseScale = 1.0f;

	// Scale for the terrain
	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0.000001))
		float Scale = 0;

	// UV Scale for the terrain
	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0.000001))
		float UVScale = 0;

	// Radius for altering the mesh
	UPROPERTY(EditAnywhere)
		float radius;

	// Depth for altering the mesh
	UPROPERTY(EditAnywhere)
		FVector Depth;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Procedural Mesh Component
	UPROPERTY(EditAnywhere)
		UMaterialInterface* Mat;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Function to alter the terrain
	UFUNCTION()
		void AlterMesh(FVector impactPoint);

private:
	// Variables for procedural mesh generation
	UProceduralMeshComponent* ProcMesh;
	TArray<FVector> Vertices;
	TArray<int> Triangles;
	TArray<FVector2D> UV0;
	TArray<FVector> Normals;
	TArray<FColor> UpVertexColors;

	// Current section ID
	int sectionID = 0;

	// Helper functions to create vertices and triangles
	void CreateVertices();
	void CreateTriangles();

};
