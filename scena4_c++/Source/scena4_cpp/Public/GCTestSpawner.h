// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GCTestSpawner.generated.h"

UCLASS()
class SCENA4_CPP_API AGCTestSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGCTestSpawner();

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> SphereClass;

	UPROPERTY(EditAnywhere)
	int32 SpawnCountPerTick;

	UPROPERTY(EditAnywhere)
	float SphereLifeSpan;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UWorld* World;

};
