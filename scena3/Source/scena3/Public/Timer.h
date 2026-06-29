// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Timer.generated.h"

UCLASS()
class SCENA3_API ATimer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	double StartTime;
	double StopTime;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Rozpoczyna pomiar czasu
	UFUNCTION(BlueprintCallable, Category = "Benchmark")
	void StartTimer();

	// Koñczy pomiar i zwraca czas w ms
	UFUNCTION(BlueprintCallable, Category = "Benchmark")
	float StopTimer();

};
