// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyPlugin/Public/MyUserWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyUserWidget() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ENGINE_API UClass* Z_Construct_UClass_UCanvasRenderTarget2D_NoRegister();
	MYPLUGIN_API UClass* Z_Construct_UClass_UMyUserWidget();
	MYPLUGIN_API UClass* Z_Construct_UClass_UMyUserWidget_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_MyPlugin();
// End Cross Module References
	DEFINE_FUNCTION(UMyUserWidget::execOnSaveImageButtonClick)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnSaveImageButtonClick();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyUserWidget::execOnLoadImageButtonClick)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnLoadImageButtonClick();
		P_NATIVE_END;
	}
	void UMyUserWidget::StaticRegisterNativesUMyUserWidget()
	{
		UClass* Class = UMyUserWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnLoadImageButtonClick", &UMyUserWidget::execOnLoadImageButtonClick },
			{ "OnSaveImageButtonClick", &UMyUserWidget::execOnSaveImageButtonClick },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMyUserWidget_OnLoadImageButtonClick_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyUserWidget_OnLoadImageButtonClick_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MyUserWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyUserWidget_OnLoadImageButtonClick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyUserWidget, nullptr, "OnLoadImageButtonClick", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyUserWidget_OnLoadImageButtonClick_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyUserWidget_OnLoadImageButtonClick_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UMyUserWidget_OnLoadImageButtonClick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyUserWidget_OnLoadImageButtonClick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyUserWidget_OnSaveImageButtonClick_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyUserWidget_OnSaveImageButtonClick_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MyUserWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyUserWidget_OnSaveImageButtonClick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyUserWidget, nullptr, "OnSaveImageButtonClick", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyUserWidget_OnSaveImageButtonClick_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyUserWidget_OnSaveImageButtonClick_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UMyUserWidget_OnSaveImageButtonClick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyUserWidget_OnSaveImageButtonClick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyUserWidget);
	UClass* Z_Construct_UClass_UMyUserWidget_NoRegister()
	{
		return UMyUserWidget::StaticClass();
	}
	struct Z_Construct_UClass_UMyUserWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CanvasRenderTarget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CanvasRenderTarget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mImagePath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_mImagePath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StartPoint_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_StartPoint;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_imageView_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_imageView;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LoadImageButton_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LoadImageButton;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SaveImageButton_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SaveImageButton;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyUserWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_MyPlugin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyUserWidget_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UMyUserWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMyUserWidget_OnLoadImageButtonClick, "OnLoadImageButtonClick" }, // 1124844966
		{ &Z_Construct_UFunction_UMyUserWidget_OnSaveImageButtonClick, "OnSaveImageButtonClick" }, // 1182855372
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyUserWidget_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyUserWidget_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "MyUserWidget.h" },
		{ "ModuleRelativePath", "Public/MyUserWidget.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyUserWidget_Statics::NewProp_CanvasRenderTarget_MetaData[] = {
		{ "Category", "RenderTarget" },
		{ "ModuleRelativePath", "Public/MyUserWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyUserWidget_Statics::NewProp_CanvasRenderTarget = { "CanvasRenderTarget", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyUserWidget, CanvasRenderTarget), Z_Construct_UClass_UCanvasRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyUserWidget_Statics::NewProp_CanvasRenderTarget_MetaData), Z_Construct_UClass_UMyUserWidget_Statics::NewProp_CanvasRenderTarget_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyUserWidget_Statics::NewProp_mImagePath_MetaData[] = {
		{ "Category", "Path" },
		{ "ModuleRelativePath", "Public/MyUserWidget.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UMyUserWidget_Statics::NewProp_mImagePath = { "mImagePath", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyUserWidget, mImagePath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyUserWidget_Statics::NewProp_mImagePath_MetaData), Z_Construct_UClass_UMyUserWidget_Statics::NewProp_mImagePath_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyUserWidget_Statics::NewProp_StartPoint_MetaData[] = {
		{ "Category", "Paint" },
		{ "ModuleRelativePath", "Public/MyUserWidget.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UMyUserWidget_Statics::NewProp_StartPoint = { "StartPoint", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyUserWidget, StartPoint), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyUserWidget_Statics::NewProp_StartPoint_MetaData), Z_Construct_UClass_UMyUserWidget_Statics::NewProp_StartPoint_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyUserWidget_Statics::NewProp_imageView_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MyUserWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyUserWidget_Statics::NewProp_imageView = { "imageView", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyUserWidget, imageView), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyUserWidget_Statics::NewProp_imageView_MetaData), Z_Construct_UClass_UMyUserWidget_Statics::NewProp_imageView_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyUserWidget_Statics::NewProp_LoadImageButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MyUserWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyUserWidget_Statics::NewProp_LoadImageButton = { "LoadImageButton", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyUserWidget, LoadImageButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyUserWidget_Statics::NewProp_LoadImageButton_MetaData), Z_Construct_UClass_UMyUserWidget_Statics::NewProp_LoadImageButton_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyUserWidget_Statics::NewProp_SaveImageButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MyUserWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyUserWidget_Statics::NewProp_SaveImageButton = { "SaveImageButton", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyUserWidget, SaveImageButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyUserWidget_Statics::NewProp_SaveImageButton_MetaData), Z_Construct_UClass_UMyUserWidget_Statics::NewProp_SaveImageButton_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMyUserWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyUserWidget_Statics::NewProp_CanvasRenderTarget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyUserWidget_Statics::NewProp_mImagePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyUserWidget_Statics::NewProp_StartPoint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyUserWidget_Statics::NewProp_imageView,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyUserWidget_Statics::NewProp_LoadImageButton,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyUserWidget_Statics::NewProp_SaveImageButton,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyUserWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyUserWidget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyUserWidget_Statics::ClassParams = {
		&UMyUserWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UMyUserWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UMyUserWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyUserWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyUserWidget_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyUserWidget_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UMyUserWidget()
	{
		if (!Z_Registration_Info_UClass_UMyUserWidget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyUserWidget.OuterSingleton, Z_Construct_UClass_UMyUserWidget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMyUserWidget.OuterSingleton;
	}
	template<> MYPLUGIN_API UClass* StaticClass<UMyUserWidget>()
	{
		return UMyUserWidget::StaticClass();
	}
	UMyUserWidget::UMyUserWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyUserWidget);
	UMyUserWidget::~UMyUserWidget() {}
	struct Z_CompiledInDeferFile_FID_Users_zreal_Desktop_Test_Plugins_MyPlugin_Source_MyPlugin_Public_MyUserWidget_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_zreal_Desktop_Test_Plugins_MyPlugin_Source_MyPlugin_Public_MyUserWidget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMyUserWidget, UMyUserWidget::StaticClass, TEXT("UMyUserWidget"), &Z_Registration_Info_UClass_UMyUserWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyUserWidget), 2665030686U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_zreal_Desktop_Test_Plugins_MyPlugin_Source_MyPlugin_Public_MyUserWidget_h_3954543320(TEXT("/Script/MyPlugin"),
		Z_CompiledInDeferFile_FID_Users_zreal_Desktop_Test_Plugins_MyPlugin_Source_MyPlugin_Public_MyUserWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_zreal_Desktop_Test_Plugins_MyPlugin_Source_MyPlugin_Public_MyUserWidget_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
