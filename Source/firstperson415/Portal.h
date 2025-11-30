// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Components/BoxComponent.h"
#include "Components/ArrowComponent.h"
#include "Portal.generated.h"

// Forward declaration
class firstperson415Character;

UCLASS()
class FIRSTPERSON415_API APortal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APortal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Static Mesh Component
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* mesh;

	// Scene Capture Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneCaptureComponent2D* sceneCapture;

	// Arrow Component
	UPROPERTY(EditAnywhere)
		UArrowComponent* rootArrow;

	// Render Target
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTextureRenderTarget2D* renderTarget;

	// Box Component
	UPROPERTY(EditAnywhere)
		UBoxComponent* boxComp;

	// Reference to the other portal
	UPROPERTY(EditAnywhere)
		APortal* otherPortal;

	// Material to apply the render target texture
	UPROPERTY(EditAnywhere)
		UMaterialInterface* mat;

	// Overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Function to set boolean in player character
	UFUNCTION()
		void SetBool(Afirstperson415Character* playerChar);

	// Function to update portals
	UFUNCTION()
		void UpdatePortals();

};
