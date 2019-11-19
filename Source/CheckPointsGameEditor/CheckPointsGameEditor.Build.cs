// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class CheckPointsGameEditor : ModuleRules
{
	public CheckPointsGameEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[]
            {
                "CheckPointsGameEditor/Public"
            });

        PrivateIncludePaths.AddRange(
            new string[]
            {
                "CheckPointsGameEditor/Private"
            });

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] { "UnrealEd", "CheckPointsGame" });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}