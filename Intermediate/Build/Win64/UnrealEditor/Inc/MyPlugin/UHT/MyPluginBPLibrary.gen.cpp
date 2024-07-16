// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyPlugin/Public/MyPluginBPLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyPluginBPLibrary() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	MYPLUGIN_API UClass* Z_Construct_UClass_UMyPluginBPLibrary();
	MYPLUGIN_API UClass* Z_Construct_UClass_UMyPluginBPLibrary_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MyPlugin();
// End Cross Module References
	DEFINE_FUNCTION(UMyPluginBPLibrary::execMyPluginSampleFunction)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Param);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=UMyPluginBPLibrary::MyPluginSampleFunction(Z_Param_Param);
		P_NATIVE_END;
	}
	void UMyPluginBPLibrary::StaticRegisterNativesUMyPluginBPLibrary()
	{
		UClass* Class = UMyPluginBPLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "MyPluginSampleFunction", &UMyPluginBPLibrary::execMyPluginSampleFunction },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMyPluginBPLibrary_MyPluginSampleFunction_Statics
	{
		struct MyPluginBPLibrary_eventMyPluginSampleFunction_Parms
		{
			float Param;
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Param;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyPluginBPLibrary_MyPluginSampleFunction_Statics::NewProp_Param = { "Param", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyPluginBPLibrary_eventMyPluginSampleFunction_Parms, Param), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyPluginBPLibrary_MyPluginSampleFunction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyPluginBPLibrary_eventMyPluginSampleFunction_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyPluginBPLibrary_MyPluginSampleFunction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyPluginBPLibrary_MyPluginSampleFunction_Statics::NewProp_Param,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyPluginBPLibrary_MyPluginSampleFunction_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyPluginBPLibrary_MyPluginSampleFunction_Statics::Function_MetaDataParams[] = {
		{ "Category", "MyPluginTesting" },
		{ "DisplayName", "Execute Sample function" },
		{ "Keywords", "MyPlugin sample test testing" },
		{ "ModuleRelativePath", "Public/MyPluginBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyPluginBPLibrary_MyPluginSampleFunction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyPluginBPLibrary, nullptr, "MyPluginSampleFunction", nullptr, nullptr, Z_Construct_UFunction_UMyPluginBPLibrary_MyPluginSampleFunction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyPluginBPLibrary_MyPluginSampleFunction_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMyPluginBPLibrary_MyPluginSampleFunction_Statics::MyPluginBPLibrary_eventMyPluginSampleFunction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyPluginBPLibrary_MyPluginSampleFunction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyPluginBPLibrary_MyPluginSampleFunction_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyPluginBPLibrary_MyPluginSampleFunction_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UMyPluginBPLibrary_MyPluginSampleFunction_Statics::MyPluginBPLibrary_eventMyPluginSampleFunction_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UMyPluginBPLibrary_MyPluginSampleFunction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyPluginBPLibrary_MyPluginSampleFunction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyPluginBPLibrary);
	UClass* Z_Construct_UClass_UMyPluginBPLibrary_NoRegister()
	{
		return UMyPluginBPLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UMyPluginBPLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyPluginBPLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_MyPlugin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyPluginBPLibrary_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UMyPluginBPLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMyPluginBPLibrary_MyPluginSampleFunction, "MyPluginSampleFunction" }, // 2178384802
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyPluginBPLibrary_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyPluginBPLibrary_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \n*\x09""Function library class.\n*\x09""Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*\x09When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*\x09""BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*\x09""BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*\x09""DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*\x09\x09\x09\x09Its lets you name the node using characters not allowed in C++ function names.\n*\x09""CompactNodeTitle - the word(s) that appear on the node.\n*\x09Keywords -\x09the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. \n*\x09\x09\x09\x09Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*\x09""Category -\x09the category your node will be under in the Blueprint drop-down menu.\n*\n*\x09""For more info on custom blueprint nodes visit documentation:\n*\x09https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation\n*/" },
#endif
		{ "IncludePath", "MyPluginBPLibrary.h" },
		{ "ModuleRelativePath", "Public/MyPluginBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "*      Function library class.\n*      Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*      When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*      BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*      BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*      DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*                              Its lets you name the node using characters not allowed in C++ function names.\n*      CompactNodeTitle - the word(s) that appear on the node.\n*      Keywords -      the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.\n*                              Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*      Category -      the category your node will be under in the Blueprint drop-down menu.\n*\n*      For more info on custom blueprint nodes visit documentation:\n*      https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation" },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyPluginBPLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyPluginBPLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyPluginBPLibrary_Statics::ClassParams = {
		&UMyPluginBPLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyPluginBPLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyPluginBPLibrary_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UMyPluginBPLibrary()
	{
		if (!Z_Registration_Info_UClass_UMyPluginBPLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyPluginBPLibrary.OuterSingleton, Z_Construct_UClass_UMyPluginBPLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMyPluginBPLibrary.OuterSingleton;
	}
	template<> MYPLUGIN_API UClass* StaticClass<UMyPluginBPLibrary>()
	{
		return UMyPluginBPLibrary::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyPluginBPLibrary);
	UMyPluginBPLibrary::~UMyPluginBPLibrary() {}
	struct Z_CompiledInDeferFile_FID_Users_zreal_Desktop_Test_Plugins_MyPlugin_Source_MyPlugin_Public_MyPluginBPLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_zreal_Desktop_Test_Plugins_MyPlugin_Source_MyPlugin_Public_MyPluginBPLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMyPluginBPLibrary, UMyPluginBPLibrary::StaticClass, TEXT("UMyPluginBPLibrary"), &Z_Registration_Info_UClass_UMyPluginBPLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyPluginBPLibrary), 2623251907U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_zreal_Desktop_Test_Plugins_MyPlugin_Source_MyPlugin_Public_MyPluginBPLibrary_h_571677309(TEXT("/Script/MyPlugin"),
		Z_CompiledInDeferFile_FID_Users_zreal_Desktop_Test_Plugins_MyPlugin_Source_MyPlugin_Public_MyPluginBPLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_zreal_Desktop_Test_Plugins_MyPlugin_Source_MyPlugin_Public_MyPluginBPLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
