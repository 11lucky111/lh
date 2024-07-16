// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MySecondPlugin/Public/MySecondActorComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMySecondActorComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	MYSECONDPLUGIN_API UClass* Z_Construct_UClass_UMySecondActorComponent();
	MYSECONDPLUGIN_API UClass* Z_Construct_UClass_UMySecondActorComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MySecondPlugin();
// End Cross Module References
	void UMySecondActorComponent::StaticRegisterNativesUMySecondActorComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMySecondActorComponent);
	UClass* Z_Construct_UClass_UMySecondActorComponent_NoRegister()
	{
		return UMySecondActorComponent::StaticClass();
	}
	struct Z_Construct_UClass_UMySecondActorComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bOverride_Sharp_MetaData[];
#endif
		static void NewProp_bOverride_Sharp_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverride_Sharp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Sharp_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Sharp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mSharpMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_mSharpMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mBlurMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_mBlurMaterial;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMySecondActorComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_MySecondPlugin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMySecondActorComponent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMySecondActorComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "MySecondActorComponent.h" },
		{ "ModuleRelativePath", "Public/MySecondActorComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_bOverride_Sharp_MetaData[] = {
		{ "Category", "Overrides" },
		{ "InlineEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/MySecondActorComponent.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	void Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_bOverride_Sharp_SetBit(void* Obj)
	{
		((UMySecondActorComponent*)Obj)->bOverride_Sharp = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_bOverride_Sharp = { "bOverride_Sharp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(UMySecondActorComponent), &Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_bOverride_Sharp_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_bOverride_Sharp_MetaData), Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_bOverride_Sharp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_Sharp_MetaData[] = {
		{ "Category", "Sharp" },
		{ "DisplayName", "Sharp" },
		{ "editcondition", "bOverride_Sharp" },
		{ "ModuleRelativePath", "Public/MySecondActorComponent.h" },
		{ "UIMax", "1" },
		{ "UIMin", "-1" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_Sharp = { "Sharp", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMySecondActorComponent, Sharp), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_Sharp_MetaData), Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_Sharp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_mSharpMaterial_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//sharp\n" },
#endif
		{ "ModuleRelativePath", "Public/MySecondActorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "sharp" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_mSharpMaterial = { "mSharpMaterial", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMySecondActorComponent, mSharpMaterial), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_mSharpMaterial_MetaData), Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_mSharpMaterial_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_mBlurMaterial_MetaData[] = {
		{ "ModuleRelativePath", "Public/MySecondActorComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_mBlurMaterial = { "mBlurMaterial", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMySecondActorComponent, mBlurMaterial), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_mBlurMaterial_MetaData), Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_mBlurMaterial_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMySecondActorComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_bOverride_Sharp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_Sharp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_mSharpMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMySecondActorComponent_Statics::NewProp_mBlurMaterial,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMySecondActorComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMySecondActorComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMySecondActorComponent_Statics::ClassParams = {
		&UMySecondActorComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UMySecondActorComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UMySecondActorComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMySecondActorComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UMySecondActorComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMySecondActorComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UMySecondActorComponent()
	{
		if (!Z_Registration_Info_UClass_UMySecondActorComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMySecondActorComponent.OuterSingleton, Z_Construct_UClass_UMySecondActorComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMySecondActorComponent.OuterSingleton;
	}
	template<> MYSECONDPLUGIN_API UClass* StaticClass<UMySecondActorComponent>()
	{
		return UMySecondActorComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMySecondActorComponent);
	UMySecondActorComponent::~UMySecondActorComponent() {}
	struct Z_CompiledInDeferFile_FID_Users_zreal_Desktop_Test_Plugins_MyPlugin_Source_MySecondPlugin_Public_MySecondActorComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_zreal_Desktop_Test_Plugins_MyPlugin_Source_MySecondPlugin_Public_MySecondActorComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMySecondActorComponent, UMySecondActorComponent::StaticClass, TEXT("UMySecondActorComponent"), &Z_Registration_Info_UClass_UMySecondActorComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMySecondActorComponent), 2565913057U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_zreal_Desktop_Test_Plugins_MyPlugin_Source_MySecondPlugin_Public_MySecondActorComponent_h_3654925548(TEXT("/Script/MySecondPlugin"),
		Z_CompiledInDeferFile_FID_Users_zreal_Desktop_Test_Plugins_MyPlugin_Source_MySecondPlugin_Public_MySecondActorComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_zreal_Desktop_Test_Plugins_MyPlugin_Source_MySecondPlugin_Public_MySecondActorComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
