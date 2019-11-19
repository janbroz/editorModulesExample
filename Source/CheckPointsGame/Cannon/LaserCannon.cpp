// Fill out your copyright notice in the Description page of Project Settings.


#include "LaserCannon.h"
#include "TargetingComponent.h"

// Sets default values
ALaserCannon::ALaserCannon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TargetingComponent = CreateDefaultSubobject<UTargetingComponent>(TEXT("TargetingComponent"));
}

// Called when the game starts or when spawned
void ALaserCannon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALaserCannon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

