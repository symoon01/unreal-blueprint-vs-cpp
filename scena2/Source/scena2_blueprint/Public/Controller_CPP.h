// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Controller_CPP.generated.h"

UCLASS()
class SCENA2_BLUEPRINT_API AController_CPP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AController_CPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Odleg³oœæ renderowania
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "environment")
	float RenderDistance = 5000.0f;
private:
	// Lista wszystkich aktorów z tym tagiem
	TArray<AActor*> EnvironmentActors;

	TArray<float> RandomOffsets;

	// WskaŸnik do gracza
	AActor* PlayerPawn;
};
