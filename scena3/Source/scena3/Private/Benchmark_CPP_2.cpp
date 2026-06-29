// Fill out your copyright notice in the Description page of Project Settings.

#include "Benchmark_CPP_2.h"
#include "Kismet/GameplayStatics.h"
#include "Trace/Trace.h"

// Sets default values
ABenchmark_CPP_2::ABenchmark_CPP_2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RandomValues.SetNum(ArraySize);
}

// Called when the game starts or when spawned
void ABenchmark_CPP_2::BeginPlay()
{
	Super::BeginPlay();
	MyTimer = Cast<ATimer>(UGameplayStatics::GetActorOfClass(GetWorld(), ATimer::StaticClass()));
	TRACE_BOOKMARK(TEXT("BENCHMARK2_CPP_START"));
	InitialIterations = TestIterations;
	InitialRepeats = RepeatCount;
	for (int32 i = 0; i < ArraySize; i++)
	{
		RandomValues[i] = FMath::FRand();
	}
}

// Called every frame
void ABenchmark_CPP_2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (newIteration) {
		newIteration = false;
		MyTimer->StartTimer();
	}
	if (RepeatCount > 0) {
		RepeatCount--;
		sum = 0.f;
		for (float Value : RandomValues)
		{
			sum += Value;
		}
		avg = sum / RandomValues.Num();
	}
	else if (TestIterations > 0) {
		TestIterations--;
		float ElapsedMs = MyTimer->StopTimer();
		TotalTimeMs += ElapsedMs;
		RepeatCount = InitialRepeats;
		for (int32 i = 0; i < ArraySize; i++)
		{
			RandomValues[i] = FMath::FRand();
		}
		newIteration = true;
	}
	else if (TestIterations<=0&&!finished) {
		finished = true;
		TRACE_BOOKMARK(TEXT("BENCHMARK2_CPP_END"));
		newIteration = false;
		AvgTimeMs = TotalTimeMs / InitialIterations;
		OnBenchmarkComplete.Broadcast(AvgTimeMs);
	}
}

