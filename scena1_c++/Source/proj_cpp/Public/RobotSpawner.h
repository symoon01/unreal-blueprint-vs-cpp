// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Robot.h"
#include "RobotSpawner.generated.h"

UCLASS()
class PROJ_CPP_API ARobotSpawner : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARobotSpawner();

	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<ARobot> RobotClass;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	int32 NumberOfRobots = 10;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	float SpawnRadius = 500.f;

	void SpawnRobots();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
