// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "ProcMeshFromStatic.generated.h"

UCLASS()
class FIRSTPERSON415_API AProcMeshFromStatic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProcMeshFromStatic();

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
	UPROPERTY()
		TArray<FVector> Vertices;

	// Triangles
	UPROPERTY()
		TArray<int> Triangles;

	// Normals
	UPROPERTY()
		TArray<FVector> Normals;

	// UVs
	TArray<FVector2D> UV0;

	// Vertex Colors
	UPROPERTY()
		TArray<FLinearColor> VertexColors;
	
	// Alternative Vertex Colors
	TArray<FColor> UpVertexColors;

	// Tangents
	TArray<FProcMeshTangent> Tangents;

	// Static Mesh Component
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* baseMesh;

private:
	UProceduralMeshComponent* procMesh;
	void GetMeshData();
	void CreateMesh();

};
