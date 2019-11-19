// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class CheckPointsGameTarget : TargetRules
{
	public CheckPointsGameTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "CheckPointsGame" } );
        if(Type == TargetType.Editor)
        {
            ExtraModuleNames.AddRange(new string[] { "CheckPointsGameEditor" });
        }
	}
}
