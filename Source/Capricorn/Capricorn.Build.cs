// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Capricorn : ModuleRules
{
	public Capricorn(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Capricorn",
			"Capricorn/Variant_Platforming",
			"Capricorn/Variant_Platforming/Animation",
			"Capricorn/Variant_Combat",
			"Capricorn/Variant_Combat/AI",
			"Capricorn/Variant_Combat/Animation",
			"Capricorn/Variant_Combat/Gameplay",
			"Capricorn/Variant_Combat/Interfaces",
			"Capricorn/Variant_Combat/UI",
			"Capricorn/Variant_SideScrolling",
			"Capricorn/Variant_SideScrolling/AI",
			"Capricorn/Variant_SideScrolling/Gameplay",
			"Capricorn/Variant_SideScrolling/Interfaces",
			"Capricorn/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
