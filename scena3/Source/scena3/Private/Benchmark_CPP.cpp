// Fill out your copyright notice in the Description page of Project Settings.

#include "Benchmark_CPP.h"
#include "Kismet/GameplayStatics.h"
#include "Trace/Trace.h"
//#include "Blueprint/WidgetBlueprintLibrary.h"
// Sets default values
ABenchmark_CPP::ABenchmark_CPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RandomValues.SetNum(ArraySize);
}

// Called when the game starts or when spawned
void ABenchmark_CPP::BeginPlay()
{
	Super::BeginPlay();
	MyTimer = Cast<ATimer>(UGameplayStatics::GetActorOfClass(GetWorld(), ATimer::StaticClass()));
	InitialIterations = TestIterations;
	TRACE_BOOKMARK(TEXT("BENCHMARK_START"));
}

// Called every frame
void ABenchmark_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TestIterations > 0) {
		TestIterations--;

		for (int32 i = 0; i < ArraySize; i++)
		{
			RandomValues[i] = FMath::FRand();
		}
		MyTimer->StartTimer();
		for (int32 Repeat = 0; Repeat < RepeatCount; Repeat++)
		{
			sum = 0.f;
			for (float Value : RandomValues)
			{
				sum += Value;
			}
			avg = sum / RandomValues.Num();
		}
		float ElapsedMs = MyTimer->StopTimer();
		TotalTimeMs += ElapsedMs;
	}
	else if(!finished) {
		finished = true;
		TRACE_BOOKMARK(TEXT("BENCHMARK_END"));
		AvgTimeMs = TotalTimeMs / InitialIterations;

		OnBenchmarkComplete.Broadcast(AvgTimeMs);
	}
}

