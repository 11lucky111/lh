// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyPlugin/Public/MyActorComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyActorComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	MYPLUGIN_API UClass* Z_Construct_UClass_UMyActorComponent();
	MYPLUGIN_API UClass* Z_Construct_UClass_UMyActorComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MyPlugin();
// End Cross Module References
	void UMyActorComponent::StaticRegisterNativesUMyActorComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyActorComponent);
	UClass* Z_Construct_UClass_UMyActorComponent_NoRegister()
	{
		return UMyActorComponent::StaticClass();
	}
	struct Z_Construct_UClass_UMyActorComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bOverride_Lift_MetaData[];
#endif
		static void NewProp_bOverride_Lift_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverride_Lift;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Lift_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Lift;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bOverride_Gamma_MetaData[];
#endif
		static void NewProp_bOverride_Gamma_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverride_Gamma;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Gamma_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Gamma;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bOverride_Gain_MetaData[];
#endif
		static void NewProp_bOverride_Gain_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverride_Gain;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Gain_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Gain;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mBrightnessMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_mBrightnessMaterial;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyActorComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_MyPlugin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyActorComponent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyActorComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "MyActorComponent.h" },
		{ "ModuleRelativePath", "Public/MyActorComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Lift_MetaData[] = {
		{ "Category", "Overrides" },
		{ "InlineEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/MyActorComponent.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	void Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Lift_SetBit(void* Obj)
	{
		((UMyActorComponent*)Obj)->bOverride_Lift = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Lift = { "bOverride_Lift", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(UMyActorComponent), &Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Lift_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Lift_MetaData), Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Lift_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyActorComponent_Statics::NewProp_Lift_MetaData[] = {
		{ "Category", "Brightness" },
		{ "DisplayName", "Lift" },
		{ "editcondition", "bOverride_Lift" },
		{ "ModuleRelativePath", "Public/MyActorComponent.h" },
		{ "UIMax", "100" },
		{ "UIMin", "-100" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMyActorComponent_Statics::NewProp_Lift = { "Lift", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyActorComponent, Lift), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyActorComponent_Statics::NewProp_Lift_MetaData), Z_Construct_UClass_UMyActorComponent_Statics::NewProp_Lift_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Gamma_MetaData[] = {
		{ "Category", "Overrides" },
		{ "InlineEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/MyActorComponent.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	void Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Gamma_SetBit(void* Obj)
	{
		((UMyActorComponent*)Obj)->bOverride_Gamma = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Gamma = { "bOverride_Gamma", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(UMyActorComponent), &Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Gamma_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Gamma_MetaData), Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Gamma_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyActorComponent_Statics::NewProp_Gamma_MetaData[] = {
		{ "Category", "Brightness" },
		{ "DisplayName", "Gamma" },
		{ "editcondition", "bOverride_Gamma" },
		{ "ModuleRelativePath", "Public/MyActorComponent.h" },
		{ "UIMax", "100" },
		{ "UIMin", "-100" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMyActorComponent_Statics::NewProp_Gamma = { "Gamma", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyActorComponent, Gamma), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyActorComponent_Statics::NewProp_Gamma_MetaData), Z_Construct_UClass_UMyActorComponent_Statics::NewProp_Gamma_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Gain_MetaData[] = {
		{ "Category", "Overrides" },
		{ "InlineEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/MyActorComponent.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	void Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Gain_SetBit(void* Obj)
	{
		((UMyActorComponent*)Obj)->bOverride_Gain = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Gain = { "bOverride_Gain", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(UMyActorComponent), &Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Gain_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Gain_MetaData), Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Gain_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyActorComponent_Statics::NewProp_Gain_MetaData[] = {
		{ "Category", "Brightness" },
		{ "DisplayName", "Gain" },
		{ "editcondition", "bOverride_Gain" },
		{ "ModuleRelativePath", "Public/MyActorComponent.h" },
		{ "UIMax", "100" },
		{ "UIMin", "-100" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMyActorComponent_Statics::NewProp_Gain = { "Gain", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyActorComponent, Gain), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyActorComponent_Statics::NewProp_Gain_MetaData), Z_Construct_UClass_UMyActorComponent_Statics::NewProp_Gain_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyActorComponent_Statics::NewProp_mBrightnessMaterial_MetaData[] = {
		{ "ModuleRelativePath", "Public/MyActorComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyActorComponent_Statics::NewProp_mBrightnessMaterial = { "mBrightnessMaterial", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyActorComponent, mBrightnessMaterial), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyActorComponent_Statics::NewProp_mBrightnessMaterial_MetaData), Z_Construct_UClass_UMyActorComponent_Statics::NewProp_mBrightnessMaterial_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMyActorComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Lift,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyActorComponent_Statics::NewProp_Lift,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Gamma,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyActorComponent_Statics::NewProp_Gamma,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyActorComponent_Statics::NewProp_bOverride_Gain,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyActorComponent_Statics::NewProp_Gain,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyActorComponent_Statics::NewProp_mBrightnessMaterial,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyActorComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyActorComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyActorComponent_Statics::ClassParams = {
		&UMyActorComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UMyActorComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UMyActorComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyActorComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyActorComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyActorComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UMyActorComponent()
	{
		if (!Z_Registration_Info_UClass_UMyActorComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyActorComponent.OuterSingleton, Z_Construct_UClass_UMyActorComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMyActorComponent.OuterSingleton;
	}
	template<> MYPLUGIN_API UClass* StaticClass<UMyActorComponent>()
	{
		return UMyActorComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyActorComponent);
	struct Z_CompiledInDeferFile_FID_Users_zreal_Desktop_Test_Plugins_MyPlugin_Source_MyPlugin_Public_MyActorComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_zreal_Desktop_Test_Plugins_MyPlugin_Source_MyPlugin_Public_MyActorComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMyActorComponent, UMyActorComponent::StaticClass, TEXT("UMyActorComponent"), &Z_Registration_Info_UClass_UMyActorComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyActorComponent), 3066767875U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_zreal_Desktop_Test_Plugins_MyPlugin_Source_MyPlugin_Public_MyActorComponent_h_3231007412(TEXT("/Script/MyPlugin"),
		Z_CompiledInDeferFile_FID_Users_zreal_Desktop_Test_Plugins_MyPlugin_Source_MyPlugin_Public_MyActorComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_zreal_Desktop_Test_Plugins_MyPlugin_Source_MyPlugin_Public_MyActorComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
