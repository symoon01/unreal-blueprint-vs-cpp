// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller_CPP.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AController_CPP::AController_CPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AController_CPP::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "environment", EnvironmentActors);

    RandomOffsets.Empty();
    //pocz¹tkowa losowa pozycja nachylenia
    for (int32 i = 0; i < EnvironmentActors.Num(); i++)
        RandomOffsets.Add(FMath::FRandRange(0.f, 10000.f));
	
}

// Called every frame
void AController_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (!PlayerPawn) return;
    FVector PlayerLocation = PlayerPawn->GetActorLocation();

    for (int32 i = 0; i < EnvironmentActors.Num(); i++)
    {
        AActor* Actor = EnvironmentActors[i];
        if (!Actor) continue;

        // obliczenie dystansu
        float Distance = FVector::Dist(PlayerLocation, Actor->GetActorLocation());
        bool bShouldBeVisible = Distance <= RenderDistance;

        // Ukrywanie/pokazywanie obiektów
        Actor->SetActorHiddenInGame(!bShouldBeVisible);
        Actor->SetActorEnableCollision(bShouldBeVisible);
        Actor->SetActorTickEnabled(bShouldBeVisible);

        //animacja ko³ysania drzew
        if (Actor->Tags.Contains(FName("tree")))
        {
            float Angle = FMath::Sin(GetWorld()->GetTimeSeconds() * 1.0f + RandomOffsets[i]) * 1.5f;
            FRotator NewRot(Angle, 0.f, 0.f);
            Actor->SetActorRotation(NewRot);
        }
    }
}

