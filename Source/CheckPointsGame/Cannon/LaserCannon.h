// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaserCannon.generated.h"

UCLASS()
class CHECKPOINTSGAME_API ALaserCannon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaserCannon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Cannon)
		class UTargetingComponent* TargetingComponent;

};
