// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "CubeDMIMod.generated.h"

class UNiagaraSystem;

UCLASS()
class FIRSTPERSON415_API ACubeDMIMod : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubeDMIMod();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Box Component
	UPROPERTY(EditAnywhere)
		UBoxComponent* boxComp;

	// Cube Mesh
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* cubeMesh;

	// Base Material
	UPROPERTY(EditAnywhere)
		UMaterialInterface* baseMat;

	// Dynamic Material Instance
	UPROPERTY()
		UMaterialInstanceDynamic* dmiMat;

	// Niagara Particle System for Color Impact
	UPROPERTY(EditAnyWhere)
	UNiagaraSystem* colorP;

	// Overlap Begin Function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
