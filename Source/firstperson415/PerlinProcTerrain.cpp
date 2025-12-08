// Fill out your copyright notice in the Description page of Project Settings.


#include "PerlinProcTerrain.h"
#include "ProceduralMeshComponent.h"
#include "KismetProceduralMeshLibrary.h"

// Sets default values
APerlinProcTerrain::APerlinProcTerrain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Root Component
	ProcMesh = CreateDefaultSubobject<UProceduralMeshComponent>("Procedural Mesh");
	ProcMesh->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void APerlinProcTerrain::BeginPlay()
{
	Super::BeginPlay();

	// Generate Terrain
	CreateVertices();
	CreateTriangles();

	// Create Mesh Section
	ProcMesh->CreateMeshSection(sectionID, Vertices, Triangles, Normals, UV0, UpVertexColors, TArray<FProcMeshTangent>(), true);

	// Apply Material
	ProcMesh->SetMaterial(0, Mat);

}

// Called every frame
void APerlinProcTerrain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APerlinProcTerrain::AlterMesh(FVector impactPoint)
{
	// Modify vertices based on impact point, radius, and depth
	for (int i = 0; i < Vertices.Num(); i++)
	{
		// Calculate distance from impact point
		FVector tempVector = impactPoint - this->GetActorLocation();

		// If within radius, modify vertex
		if (FVector(Vertices[i] - tempVector).Size() < radius)
		{
			// Move vertex down by Depth
			Vertices[i] = Vertices[i] - Depth;

			// Update the mesh section
			ProcMesh->UpdateMeshSection(sectionID, Vertices, Normals, UV0, UpVertexColors, TArray<FProcMeshTangent>());
		}
	}
}

void APerlinProcTerrain::CreateVertices()
{
	// Loop through X and Y to create vertices
	for (int X = 0; X <= XSize; X++)
	{
		for (int Y = 0; Y <= YSize; Y++)
		{
			// Generate Z value using Perlin Noise
			float Z = FMath::PerlinNoise2D(FVector2D(X * NoiseScale + 0.1, Y * NoiseScale + 0.1)) * ZMultiplier;

			// Print Z value for debugging
			GEngine->AddOnScreenDebugMessage(-1, 999.0f, FColor::Yellow, FString::Printf(TEXT("Z %f"), Z));

			// Create Vertex for the terrain
			Vertices.Add(FVector(X * Scale, Y * Scale, Z));

			// Simple UV Mapping
			UV0.Add(FVector2D(X * UVScale, Y * UVScale));
		}
	}
}

void APerlinProcTerrain::CreateTriangles()
{
	// Initialize vertex index
	int Vertex = 0;

	// Loop through X and Y to create triangles
	for (int X = 0; X < XSize; X++)
	{
		for (int Y = 0; Y < YSize; Y++)
		{
			Triangles.Add(Vertex);
			Triangles.Add(Vertex + 1);
			Triangles.Add(Vertex + YSize + 1);
			Triangles.Add(Vertex + 1);
			Triangles.Add(Vertex + YSize + 2);
			Triangles.Add(Vertex + YSize + 1);

			// Move to the next vertex
			Vertex++;

		}

		// Move to the next row
		Vertex++;

	}
}

