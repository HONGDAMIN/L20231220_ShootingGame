// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ShootingCodeGame : ModuleRules
{
	public ShootingCodeGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput","UMG" }); //ShootingHudWidget 사용을 위해 UMG파일 추가 
	}
}
