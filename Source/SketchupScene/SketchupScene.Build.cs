// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SketchupScene : ModuleRules
{
	public SketchupScene(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
        );
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
        );
			
		
		PublicDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
        );
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[] {
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "Slate",
                "SlateCore",
                "EditorStyle",
                "UnrealEd",
                "RenderCore",
                "LevelEditor",
                "NavigationSystem",
                "EditorSubsystem",
                "Projects",
                "InteractiveToolsFramework",
                "EditorInteractiveToolsFramework"
			}
        );
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[] {
				// ... add any modules that your module loads dynamically here ...
			}
        );
	}
}