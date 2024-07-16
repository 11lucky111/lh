// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTools.h"

#include <IDesktopPlatform.h>
#include "Developer\DesktopPlatform\Public\DesktopPlatformModule.h"
#include <wtypes.h>
#include <Kismet/KismetRenderingLibrary.h>
#include "Engine/World.h"
#include <ImageUtils.h>
MyTools::MyTools()
{
}

MyTools::~MyTools()
{
}

TSharedPtr<IImageWrapper> MyTools::GetImageWrapperByExtention(const FString& ImagePath)
{
	IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
	if (ImagePath.EndsWith(".png"))
	{
		return ImageWrapperModule.CreateImageWrapper(EImageFormat::PNG);
	}
	else if(ImagePath.EndsWith(".jpg"))
	{
		return ImageWrapperModule.CreateImageWrapper(EImageFormat::JPEG);
	}
	return nullptr;
}

UMaterialInstanceDynamic* MyTools::CreateMaterial(FString assertName, FString instanceName)
{
	FString assertPath = TEXT("/MyPlugin/") + assertName + "." + assertName;
	UMaterialInterface* MaterialInterface = LoadObject<UMaterialInterface>(nullptr, *assertPath);
	if (MaterialInterface) {
		//uMat = UMaterialInstanceDynamic::Create(MaterialInterface, NULL, FName(instanceName));
		return UMaterialInstanceDynamic::Create(MaterialInterface, NULL, FName(instanceName));

	}
	return nullptr;
}

TArray<FColor> MyTools::GetPictureRGBPixel(UTexture2D* RGBTexture, int32& OutX, int32& OutY, bool IsHDR)
{
	if (!IsValid(RGBTexture) || !RGBTexture->GetPlatformData())
		return TArray<FColor>();

	TArray<FColor> ColorArray;

	//TextureCompressionSettings OldCompressionSettings = RGBTexture->CompressionSettings;
	//TextureMipGenSettings OldMipGenSettings = RGBTexture->MipGenSettings;
	bool OldSRGB = RGBTexture->SRGB;
	if (IsHDR)
	{
		RGBTexture->CompressionSettings = TextureCompressionSettings::TC_HDR;
	}
	else
	{
		RGBTexture->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;
	}
	
	//RGBTexture->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
	RGBTexture->SRGB = false;
	RGBTexture->UpdateResource();
	const FColor* Colors = static_cast<const FColor*>(RGBTexture->GetPlatformData()->Mips[0].BulkData.LockReadOnly());
	
	OutX = RGBTexture->GetSizeX();
	OutY = RGBTexture->GetSizeY();
	for (int32 y = 0; y < OutY; y++)
	{
		for (int32 x = 0; x < OutX; x++)
		{
			FColor PixelColor = Colors[y * OutX + x];
			ColorArray.Add(PixelColor);
		}
	}
	RGBTexture->GetPlatformData()->Mips[0].BulkData.Unlock();

	//RGBTexture->CompressionSettings = OldCompressionSettings;
	//RGBTexture->MipGenSettings = OldMipGenSettings;
	RGBTexture->SRGB = OldSRGB;
	RGBTexture->UpdateResource();
	return ColorArray;
}

TArray<FLinearColor> MyTools::GetPictureRGBAPixel(UTexture2D* RGBTexture, int32& OutX, int32& OutY, bool IsHDR)
{
	if (!IsValid(RGBTexture) || !RGBTexture->GetPlatformData())
		return TArray<FLinearColor>();

	TArray<FLinearColor> ColorArray;

	bool OldSRGB = RGBTexture->SRGB;
	if (IsHDR)
	{
		RGBTexture->CompressionSettings = TextureCompressionSettings::TC_HDR;
	}
	else
	{
		RGBTexture->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;
	}

	RGBTexture->SRGB = false;
	RGBTexture->UpdateResource();

	// 锁定纹理的第一个 Mip level 的 BulkData 以进行只读操作
	const FFloat16Color* Colors = static_cast<const FFloat16Color*>(RGBTexture->GetPlatformData()->Mips[0].BulkData.LockReadOnly());

	// 获取纹理的宽度和高度
	OutX = RGBTexture->GetSizeX();
	OutY = RGBTexture->GetSizeY();

	// 遍历每一个像素，将其颜色值添加到颜色数组中
	for (int32 y = 0; y < OutY; y++)
	{
		for (int32 x = 0; x < OutX; x++)
		{
			FFloat16Color PixelColor = Colors[y * OutX + x]; // 获取像素颜色
			FLinearColor LinearColor(PixelColor); // 将 FFloat16Color 转换为 FLinearColor
			ColorArray.Add(LinearColor); // 添加到颜色数组中
		}
	}

	// 解锁纹理的 BulkData
	RGBTexture->GetPlatformData()->Mips[0].BulkData.Unlock();

	// 恢复旧的 sRGB 设置
	RGBTexture->SRGB = OldSRGB;
	RGBTexture->UpdateResource();

	// 返回颜色数组
	return ColorArray;
}

TArray<FColor> MyTools::GetRenderTargetPixelData(UCanvasRenderTarget2D* RenderTarget, int32& OutWidth, int32& OutHeight)
{
	if (!IsValid(RenderTarget) || !RenderTarget->GetResource())
		return TArray<FColor>();

	TArray<FColor> PixelData;

	// 获取纹理的宽度和高度
	OutWidth = RenderTarget->SizeX;
	OutHeight = RenderTarget->SizeY;

	// 获取底层纹理资源
	FTextureRenderTarget2DResource* TextureResource = static_cast<FTextureRenderTarget2DResource*>(RenderTarget->GetRenderTargetResource());

	// 锁定渲染目标的读取访问
	TArray<FColor> RawData;
	if (TextureResource->ReadPixels(RawData))
	{
		PixelData = RawData;
	}

	return PixelData;
}

FColor MyTools::GetMousePointColor(float x, float y, bool InUsingMosuePoint)
{
	//获取当前HDC，不懂HDC的，可以看看C++窗口编程
	//::前面啥也不写，代表全局函数的调用
	HDC tempHDC = ::GetDC(NULL);
	//创建临时变量存储鼠标值
	POINT pt1;
	//判断是否用鼠标位置获取，不是的话，则用输入值获取，是的话用鼠标位置获取像素
	if (InUsingMosuePoint)
		GetCursorPos(&pt1);
	else { pt1.x = x; pt1.y = y; }
	//获取当前像素点颜色值
	COLORREF clr = ::GetPixel(tempHDC, pt1.x, pt1.y);
	//获取颜色的R G B值
	int R = GetRValue(clr);
	int G = GetGValue(clr);
	int B = GetBValue(clr);
	//释放当前HDC
	::ReleaseDC(NULL, tempHDC);
	//创建应当返回的颜色值
	FColor Color;
	Color.R = R;
	Color.G = G;
	Color.B = B;
	Color.A = 255;
	UE_LOG(LogTemp, Warning, TEXT("%s"), *Color.ToString());
	return Color;
}

UTexture2D* MyTools::LoadTextureFromDisk(const FString& ImagePath)
{
	TSharedPtr<IImageWrapper> ImageWrapper = GetImageWrapperByExtention(ImagePath);
	TArray<uint8> RawFileData;
	if (!FFileHelper::LoadFileToArray(RawFileData,*ImagePath))
	{
		return nullptr;
	}
	if (ImageWrapper->SetCompressed(RawFileData.GetData(), RawFileData.Num()))
	{
		TArray<uint8> UncompressedRGBA;
		if (ImageWrapper->GetRaw(ERGBFormat::BGRA,8,UncompressedRGBA))
		{
			// 创建纹理
			UTexture2D* Texture = UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), PF_B8G8R8A8);
			if (!Texture)
			{
				return nullptr;
			}

			// 复制解码后的图片数据到纹理
			FTexturePlatformData* PlatformData = Texture->GetPlatformData();
			void* TextureData = PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
			FMemory::Memcpy(TextureData, UncompressedRGBA.GetData(), UncompressedRGBA.Num());
			PlatformData->Mips[0].BulkData.Unlock();

			Texture->UpdateResource();

			return Texture;
		}
	}
	return nullptr;
}

TArray<FString> MyTools::OpenWindowsFiles()
{
	TArray<FString> OpenFileNames;//获取的文件绝对路径
	FString ExtensionStr = TEXT("*.*");//文件类型

	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	DesktopPlatform->OpenFileDialog(nullptr, TEXT("ywy文件管理器"), FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()), TEXT(""), *ExtensionStr, EFileDialogFlags::None, OpenFileNames);
	return OpenFileNames;
}

UTexture2D* MyTools::CopyRenderTargetToTexture(UCanvasRenderTarget2D* RT)
{

	FImage Image;
	if (!FImageUtils::GetRenderTargetImage(RT, Image))
	{
		return nullptr;
	}

	TArray64<uint8> RawFileData;
	if (!FImageUtils::CompressImage(RawFileData, TEXT("EXR"), Image))
	{
		return nullptr;
	}

	IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
	TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::EXR);

	if (ImageWrapper->SetCompressed(RawFileData.GetData(), RawFileData.Num()))
	{
		TArray<uint8> UncompressedRGBA;
		if (ImageWrapper->GetRaw(ERGBFormat::RGBAF, 16, UncompressedRGBA))
		{
			// 创建纹理
			UTexture2D* Texture = UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), PF_FloatRGBA);
			if (!Texture)
			{
				return nullptr;
			}

			// 复制解码后的图片数据到纹理
			FTexturePlatformData* PlatformData = Texture->GetPlatformData();
			void* TextureData = PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);

			// Debug: 打印UncompressedRGBA数组的大小和内容
			//UE_LOG(LogTemp, Warning, TEXT("UncompressedRGBA Size: %d"), UncompressedRGBA.Num());
			//for (int32 i = 0; i < UncompressedRGBA.Num(); i += 4)
			//{
			//	UE_LOG(LogTemp, Warning, TEXT("R: %f, G: %f, B: %f, A: %f"),
			//		UncompressedRGBA[i], UncompressedRGBA[i + 1], UncompressedRGBA[i + 2], UncompressedRGBA[i + 3]);
			//}

			FMemory::Memcpy(TextureData, UncompressedRGBA.GetData(), UncompressedRGBA.Num());
			PlatformData->Mips[0].BulkData.Unlock();

			Texture->UpdateResource();

			return Texture;
		}
	}
	return nullptr;

	//FImage Image;
	//if (!FImageUtils::GetRenderTargetImage(RT, Image))
	//{
	//	return nullptr;
	//}
	//TArray64<uint8> RawFileData;
	//if (!FImageUtils::CompressImage(RawFileData, TEXT("EXR"), Image))
	//{
	//	return nullptr;
	//}
	//IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));

	//TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::EXR);
	//if (ImageWrapper->SetCompressed(RawFileData.GetData(), RawFileData.Num()))
	//{
	//	TArray<uint8> UncompressedRGBA;
	//	if (ImageWrapper->GetRaw(ERGBFormat::RGBAF, 16, UncompressedRGBA))
	//	{
	//		// 创建纹理
	//		UTexture2D* Texture = UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), PF_FloatRGBA);
	//		if (!Texture)
	//		{
	//			return nullptr;
	//		}

	//		// 复制解码后的图片数据到纹理
	//		FTexturePlatformData* PlatformData = Texture->GetPlatformData();
	//		void* TextureData = PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
	//		FMemory::Memcpy(TextureData, UncompressedRGBA.GetData(), UncompressedRGBA.Num());
	//		PlatformData->Mips[0].BulkData.Unlock();

	//		Texture->UpdateResource();

	//		return Texture;
	//	}
	//}
	//UE_LOG(LogTemp, Warning, TEXT("123"));
	//return nullptr;

//**************************************************************************************************************
	//if (!RenderTarget) return nullptr;

	//FTextureRenderTargetResource* RenderTargetResource = RenderTarget->GameThread_GetRenderTargetResource();
	//if (!RenderTargetResource) return nullptr;

	//// 创建一个新的UTexture2D来存储数据
	//UTexture2D* Texture = UTexture2D::CreateTransient(RenderTarget->SizeX, RenderTarget->SizeY, RenderTarget->GetFormat());
	//if (!Texture) return nullptr;

	//FTexture2DMipMap& Mip = Texture->PlatformData->Mips[0];
	//void* Data = Mip.BulkData.Lock(LOCK_READ_WRITE);

	//// 从渲染目标资源中读取像素数据
	//TArray<FColor> OutBMP;
	//RenderTargetResource->ReadPixels(OutBMP);

	//// 将数据复制到新的纹理中
	//FMemory::Memcpy(Data, OutBMP.GetData(), OutBMP.Num() * sizeof(FColor));

	//Mip.BulkData.Unlock();
	//Texture->UpdateResource();
	// ########################################################################################################
	//if (RT != nullptr)
	//{
	//	UTexture2D* Result = NULL;

	//	// Check render target size is valid and power of two.
	//	const bool bIsValidSize = true;
	//	// The r2t resource will be needed to read its surface contents
	//	FRenderTarget* RenderTarget = RT->GameThread_GetRenderTargetResource();

	//	const EPixelFormat PixelFormat = RT->GetFormat();
	//	ETextureSourceFormat TextureFormat = TSF_Invalid;
	//	switch (PixelFormat)
	//	{
	//	case PF_B8G8R8A8:
	//		TextureFormat = TSF_BGRA8;
	//		break;
	//	case PF_FloatRGBA:
	//		TextureFormat = TSF_RGBA16F;
	//		break;
	//	case PF_G8:
	//		TextureFormat = TSF_G8;
	//		break;
	//	default:
	//	{
	//		return nullptr;
	//	}
	//	}

	//	// exit if source is not compatible.
	//	if (bIsValidSize == false || RenderTarget == NULL || TextureFormat == TSF_Invalid)
	//	{
	//		return Result;
	//	}

	//	// create the 2d texture
	//	Result = UTexture2D::CreateTransient(RT->SizeX, RT->SizeY, PF_B8G8R8A8);

	//	// Lock the texture so it can be modified
	//	auto& BulkD = Result->PlatformData->Mips[0].BulkData;
	//	uint8* MipData = static_cast<uint8*>(BulkD.Lock(LOCK_READ_WRITE));

	//	TextureCompressionSettings CompressionSettingsForTexture = TC_HDR;

	//	TArray<FColor> SurfData;
	//	RenderTarget->ReadPixels(SurfData);

	//	// read the 2d surface
	//	if (TextureFormat == TSF_BGRA8)
	//	{
	//		check(BulkD.GetBulkDataSize() == SurfData.Num() * sizeof(FColor));
	//		FMemory::Memcpy(MipData, SurfData.GetData(), BulkD.GetBulkDataSize());
	//	}
	//	Result->LODGroup = TextureGroup::TEXTUREGROUP_UI;
	//	Result->SRGB = false;
	//	Result->CompressionSettings = CompressionSettingsForTexture;
	//	Result->Filter = TextureFilter::TF_Trilinear;
	//	BulkD.Unlock();
	//	Result->UpdateResource();
	//	return Result;
	//}
	//return nullptr;
	//******************************************************************************
	//UTexture* auxTex = static_cast<UTexture*>(RT);
	//return static_cast<UTexture2D*>(auxTex);
}
// 函数：将纹理的数据复制回渲染目标
void MyTools::CopyTextureToRenderTarget(UObject* WorldContextObject, UCanvasRenderTarget2D* RenderTarget, UMaterialInstanceDynamic* MaterialIns, UTexture2D* Texture)
{
	if (!RenderTarget || !Texture) return;

	//FTextureRenderTargetResource* RenderTargetResource = RenderTarget->GameThread_GetRenderTargetResource();
	//if (!RenderTargetResource) return;

	//FTexture2DMipMap& Mip = Texture->PlatformData->Mips[0];
	//void* Data = Mip.BulkData.Lock(LOCK_READ_ONLY);
	//
	//TArray<FColor> PixelData;
	//PixelData.AddUninitialized(Texture->GetSizeX() * Texture->GetSizeY());
	//FMemory::Memcpy(PixelData.GetData(), Data, PixelData.Num() * sizeof(FColor));

	//Mip.BulkData.Unlock();

	// 将数据写入渲染目标
	MaterialIns->SetTextureParameterValue(TEXT("texture"), Texture);
	UKismetRenderingLibrary::DrawMaterialToRenderTarget(WorldContextObject, RenderTarget, MaterialIns);
	MaterialIns->SetTextureParameterValue(TEXT("texture"), RenderTarget);
	/*FUpdateTextureRegion2D Region(0, 0, 0, 0, RenderTarget->SizeX, RenderTarget->SizeY);
	RenderTargetResource->UpdateTextureRegion(0, 1, &Region, RenderTarget->SizeX * sizeof(FColor), (uint32)sizeof(FColor), (uint8*)PixelData.GetData());*/
}

// 在需要调整大小时调用
void MyTools::ResizeRenderTarget(UObject* WorldContextObject, UCanvasRenderTarget2D* RenderTarget, UMaterialInstanceDynamic* MaterialIns, int32 NewWidth, int32 NewHeight)
{
	if (!RenderTarget) 
		return;

	// 复制当前数据到一个纹理
	UTexture2D* TempTexture = CopyRenderTargetToTexture(RenderTarget);

	// 调整渲染目标大小
	RenderTarget->ResizeTarget(NewWidth, NewHeight);

	// 复制数据回渲染目标
	CopyTextureToRenderTarget(WorldContextObject,RenderTarget, MaterialIns, TempTexture);

}