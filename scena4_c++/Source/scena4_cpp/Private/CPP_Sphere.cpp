// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Sphere.h"

// Sets default values
ACPP_Sphere::ACPP_Sphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
    RootComponent = Mesh;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(TEXT("/Engine/BasicShapes/Sphere"));
    if (SphereMesh.Succeeded())
        Mesh->SetStaticMesh(SphereMesh.Object);

    Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or when spawned
void ACPP_Sphere::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Sphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

