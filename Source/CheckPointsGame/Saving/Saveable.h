// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"
#include "Saveable.generated.h"

USTRUCT()
struct FSaveDataRecord
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(SaveGame)
		UClass* ActorClass;

	UPROPERTY(SaveGame)
		FTransform ActorTransform;

	UPROPERTY(SaveGame)
		FString ActorName;

	UPROPERTY(SaveGame)
		uint32 ObjectID = -1;

	UPROPERTY(SaveGame)
		TArray<uint32> PointerList;

	UPROPERTY(SaveGame)
		TArray<uint8> Data;

	FORCEINLINE FArchive& Serialize(FArchive& Ar)
	{
		Ar << ActorClass;
		Ar << ActorTransform;
		Ar << ActorName;
		Ar << ObjectID;
		Ar << Data;
		return Ar;
	}
};

struct FSaveGameArchive : public FObjectAndNameAsStringProxyArchive
{
	FSaveGameArchive(FArchive& InInnerArchive, bool bInLoadIfFindFails)
		: FObjectAndNameAsStringProxyArchive(InInnerArchive, bInLoadIfFindFails)
	{
		ArIsSaveGame = true;
	}
};


// This class does not need to be modified.
//UINTERFACE(MinimalAPI)
UINTERFACE(Blueprintable)
class USaveable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CHECKPOINTSGAME_API ISaveable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual FSaveDataRecord SaveToRecord();

	virtual void LoadFromRecord(FSaveDataRecord Record);

	virtual bool IsTransient() const;

	virtual void RelinkPointers(TMap<uint32, AActor*> ObjectDB, TArray<uint32> OIDList);
};
