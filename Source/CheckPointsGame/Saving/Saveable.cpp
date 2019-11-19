// Fill out your copyright notice in the Description page of Project Settings.


#include "Saveable.h"

// Add default functionality here for any ISaveable functions that are not pure virtual.


FSaveDataRecord ISaveable::SaveToRecord()
{
	return FSaveDataRecord();
}

void ISaveable::LoadFromRecord(FSaveDataRecord Record)
{

}

void ISaveable::RelinkPointers(TMap<uint32, AActor*> ObjectDB, TArray<uint32> OIDList)
{

}

bool ISaveable::IsTransient() const
{
	return false;
}