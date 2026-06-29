// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class scena4_cppTarget : TargetRules
{
	public scena4_cppTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;
		ExtraModuleNames.Add("scena4_cpp");

		if (Configuration == UnrealTargetConfiguration.Shipping)
		{
			bOverrideBuildEnvironment = true;
			GlobalDefinitions.Add("UE_TRACE_ENABLED=1");
		}
	}
}
