// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "TargetingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHECKPOINTSGAME_API UTargetingComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTargetingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void DeleteTarget(int32 DeleteIndex);
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Cannon)
		TArray<FVector> Targets;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Cannon)
		float TimeBetweenAttacks;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Cannon)
		int32 CurrentAttackIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Colors)
		FLinearColor EditorSelectedColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Colors)
		FLinearColor EditorUnselectedColor;
};

