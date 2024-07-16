// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyPlugin_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_MyPlugin;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_MyPlugin()
	{
		if (!Z_Registration_Info_UPackage__Script_MyPlugin.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/MyPlugin",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x0E65D8FF,
				0x40661E7B,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_MyPlugin.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_MyPlugin.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_MyPlugin(Z_Construct_UPackage__Script_MyPlugin, TEXT("/Script/MyPlugin"), Z_Registration_Info_UPackage__Script_MyPlugin, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x0E65D8FF, 0x40661E7B));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
