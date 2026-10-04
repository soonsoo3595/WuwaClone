// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WuwaClone : ModuleRules
{
	public WuwaClone(ReadOnlyTargetRules Target) : base(Target)
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
			"WuwaClone",
			"WuwaClone/Variant_Platforming",
			"WuwaClone/Variant_Platforming/Animation",
			"WuwaClone/Variant_Combat",
			"WuwaClone/Variant_Combat/AI",
			"WuwaClone/Variant_Combat/Animation",
			"WuwaClone/Variant_Combat/Gameplay",
			"WuwaClone/Variant_Combat/Interfaces",
			"WuwaClone/Variant_Combat/UI",
			"WuwaClone/Variant_SideScrolling",
			"WuwaClone/Variant_SideScrolling/AI",
			"WuwaClone/Variant_SideScrolling/Gameplay",
			"WuwaClone/Variant_SideScrolling/Interfaces",
			"WuwaClone/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
