// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <IImageWrapperModule.h>
#include <Engine/CanvasRenderTarget2D.h>
/**
 * 
 */
class MYPLUGIN_API MyTools
{
public:
	MyTools();
	~MyTools();

public:
	static UTexture2D* LoadTextureFromDisk(const FString& ImagePath);
	static TArray<FString> OpenWindowsFiles();
	static TSharedPtr<IImageWrapper> GetImageWrapperByExtention(const FString& ImagePath);
	static UMaterialInstanceDynamic* CreateMaterial(FString assertName, FString instanceName);

	static TArray<FColor> GetPictureRGBPixel(class UTexture2D* RGBTexture, int32& OutX, int32& OutY, bool IsHDR);
	static TArray<FLinearColor> GetPictureRGBAPixel(UTexture2D* RGBTexture, int32& OutX, int32& OutY, bool IsHDR);
	static TArray<FColor> GetRenderTargetPixelData(UCanvasRenderTarget2D* RenderTarget, int32& OutWidth, int32& OutHeight);

	static FColor  GetMousePointColor(float x = 0.f, float y = 0.f, bool InUsingMosuePoint = true);
	static UTexture2D* CopyRenderTargetToTexture(UCanvasRenderTarget2D* RenderTarget);
	static void CopyTextureToRenderTarget(UObject* WorldContextObject, UCanvasRenderTarget2D* RenderTarget, UMaterialInstanceDynamic* MaterialIns, UTexture2D* Texture);
	static void ResizeRenderTarget(UObject* WorldContextObject, UCanvasRenderTarget2D* RenderTarget, UMaterialInstanceDynamic* MaterialIns, int32 NewWidth, int32 NewHeight);

};
