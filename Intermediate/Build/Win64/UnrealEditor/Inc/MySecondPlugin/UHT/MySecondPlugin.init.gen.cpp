// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMySecondPlugin_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_MySecondPlugin;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_MySecondPlugin()
	{
		if (!Z_Registration_Info_UPackage__Script_MySecondPlugin.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/MySecondPlugin",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x51504A92,
				0x36CADA68,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_MySecondPlugin.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_MySecondPlugin.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_MySecondPlugin(Z_Construct_UPackage__Script_MySecondPlugin, TEXT("/Script/MySecondPlugin"), Z_Registration_Info_UPackage__Script_MySecondPlugin, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x51504A92, 0x36CADA68));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
