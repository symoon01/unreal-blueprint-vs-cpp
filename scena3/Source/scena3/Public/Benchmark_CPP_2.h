// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Timer.h"
#include "Benchmark_CPP_2.generated.h"

// Event dispatcher do powiadomienia BP o zakoñczeniu benchmarku
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBenchmarkComplete2, float, AvgTimeMs);

UCLASS()
class SCENA3_API ABenchmark_CPP_2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABenchmark_CPP_2();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Benchmark")
	int32 ArraySize = 10000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Benchmark")
	int32 RepeatCount = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Benchmark")
	int32 TestIterations = 10;

	// --- Wynik ---
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Benchmark")
	float AvgTimeMs = 0.f;

	// Event dispatcher do powiadomienia BP
	UPROPERTY(BlueprintAssignable, Category = "Benchmark")
	FOnBenchmarkComplete2 OnBenchmarkComplete;

private:
	TArray<float> RandomValues;
	float TotalTimeMs = 0.f;
	ATimer* MyTimer;
	int32 InitialIterations;
	int32 InitialRepeats;
	bool finished = false;
	bool newIteration = true;
	float sum = 0.f;
	float avg = 0.f;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
