// Fill out your copyright notice in the Description page of Project Settings.


#include "Robot.h"

// Sets default values
ARobot::ARobot()
{
	PrimaryActorTick.bCanEverTick = true;

	ChooseNewDirection();
	ChangeHandRotation();
}

// Called when the game starts or when spawned
void ARobot::BeginPlay()
{
	Super::BeginPlay();
    GetWorldTimerManager().SetTimer(DirectionTimerHandle, this, &ARobot::ChooseNewDirection, 5.f, true);
    GetWorldTimerManager().SetTimer(HandTimerHandle, this, &ARobot::ChangeHandRotation, 1.f, true);
}
// Called every frame
void ARobot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    AddMovementInput(MovementDirection, 1.f);

}
void ARobot::ChooseNewDirection()
{
    float RandX = FMath::FRandRange(-1.f, 1.f);
    float RandY = FMath::FRandRange(-1.f, 1.f);
    MovementDirection = FVector(RandX, RandY, 0.f).GetSafeNormal();
}

void ARobot::ChangeHandRotation()
{
    float RandomY = FMath::FRandRange(0.f, 90.f);
    float RandomZ = FMath::FRandRange(-90.f, 90.f);

    ArmRotationOffset = FRotator(0.f, RandomY, RandomZ);
}

// Called to bind functionality to input
void ARobot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}