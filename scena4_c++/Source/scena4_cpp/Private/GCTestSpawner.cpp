// Fill out your copyright notice in the Description page of Project Settings.


#include "GCTestSpawner.h"

// Sets default values
AGCTestSpawner::AGCTestSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnCountPerTick = 50;
	SphereLifeSpan = 1.0f;

}

// Called when the game starts or when spawned
void AGCTestSpawner::BeginPlay()
{
	Super::BeginPlay();
    World = GetWorld();
}

// Called every frame
void AGCTestSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (!SphereClass || !World) return;

    for (int i = 0; i < SpawnCountPerTick; ++i)
    {
        FVector RandLoc = FVector(
            FMath::FRandRange(-5000.f, 5000.f),
            FMath::FRandRange(-5000.f, 5000.f),
            100.f
        );

        AActor* Sphere = World->SpawnActor<AActor>(SphereClass, RandLoc, FRotator::ZeroRotator);
        if (Sphere)
        {
            Sphere->SetLifeSpan(SphereLifeSpan);
        }
    }
}

