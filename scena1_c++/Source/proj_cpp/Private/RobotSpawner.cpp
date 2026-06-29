// Fill out your copyright notice in the Description page of Project Settings.


#include "RobotSpawner.h"

// Sets default values
ARobotSpawner::ARobotSpawner()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARobotSpawner::BeginPlay()
{
	Super::BeginPlay();
    SpawnRobots();
	
}

// Called every frame
void ARobotSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARobotSpawner::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ARobotSpawner::SpawnRobots()
{
    if (!RobotClass) return;

    UWorld* World = GetWorld();
    if (!World) return;

    for (int32 i = 0; i < NumberOfRobots; ++i)
    {
        float RandX = FMath::FRandRange(-SpawnRadius, SpawnRadius);
        float RandY = FMath::FRandRange(-SpawnRadius, SpawnRadius);

        FVector SpawnLocation = GetActorLocation() + FVector(RandX, RandY, 200.f);

        ARobot* SpawnedRobot = World->SpawnActor<ARobot>(RobotClass, SpawnLocation, FRotator::ZeroRotator);

        if (SpawnedRobot)
        {
            SpawnedRobot->SpawnDefaultController();
        }
    }
}