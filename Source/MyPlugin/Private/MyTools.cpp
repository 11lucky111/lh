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

	// ��������ĵ�һ�� Mip level �� BulkData �Խ���ֻ������
	const FFloat16Color* Colors = static_cast<const FFloat16Color*>(RGBTexture->GetPlatformData()->Mips[0].BulkData.LockReadOnly());

	// ��ȡ����Ŀ�Ⱥ͸߶�
	OutX = RGBTexture->GetSizeX();
	OutY = RGBTexture->GetSizeY();

	// ����ÿһ�����أ�������ɫֵ��ӵ���ɫ������
	for (int32 y = 0; y < OutY; y++)
	{
		for (int32 x = 0; x < OutX; x++)
		{
			FFloat16Color PixelColor = Colors[y * OutX + x]; // ��ȡ������ɫ
			FLinearColor LinearColor(PixelColor); // �� FFloat16Color ת��Ϊ FLinearColor
			ColorArray.Add(LinearColor); // ��ӵ���ɫ������
		}
	}

	// ��������� BulkData
	RGBTexture->GetPlatformData()->Mips[0].BulkData.Unlock();

	// �ָ��ɵ� sRGB ����
	RGBTexture->SRGB = OldSRGB;
	RGBTexture->UpdateResource();

	// ������ɫ����
	return ColorArray;
}

TArray<FColor> MyTools::GetRenderTargetPixelData(UCanvasRenderTarget2D* RenderTarget, int32& OutWidth, int32& OutHeight)
{
	if (!IsValid(RenderTarget) || !RenderTarget->GetResource())
		return TArray<FColor>();

	TArray<FColor> PixelData;

	// ��ȡ����Ŀ�Ⱥ͸߶�
	OutWidth = RenderTarget->SizeX;
	OutHeight = RenderTarget->SizeY;

	// ��ȡ�ײ�������Դ
	FTextureRenderTarget2DResource* TextureResource = static_cast<FTextureRenderTarget2DResource*>(RenderTarget->GetRenderTargetResource());

	// ������ȾĿ��Ķ�ȡ����
	TArray<FColor> RawData;
	if (TextureResource->ReadPixels(RawData))
	{
		PixelData = RawData;
	}

	return PixelData;
}

FColor MyTools::GetMousePointColor(float x, float y, bool InUsingMosuePoint)
{
	//��ȡ��ǰHDC������HDC�ģ����Կ���C++���ڱ��
	//::ǰ��ɶҲ��д������ȫ�ֺ����ĵ���
	HDC tempHDC = ::GetDC(NULL);
	//������ʱ�����洢���ֵ
	POINT pt1;
	//�ж��Ƿ������λ�û�ȡ�����ǵĻ�����������ֵ��ȡ���ǵĻ������λ�û�ȡ����
	if (InUsingMosuePoint)
		GetCursorPos(&pt1);
	else { pt1.x = x; pt1.y = y; }
	//��ȡ��ǰ���ص���ɫֵ
	COLORREF clr = ::GetPixel(tempHDC, pt1.x, pt1.y);
	//��ȡ��ɫ��R G Bֵ
	int R = GetRValue(clr);
	int G = GetGValue(clr);
	int B = GetBValue(clr);
	//�ͷŵ�ǰHDC
	::ReleaseDC(NULL, tempHDC);
	//����Ӧ�����ص���ɫֵ
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
			// ��������
			UTexture2D* Texture = UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), PF_B8G8R8A8);
			if (!Texture)
			{
				return nullptr;
			}

			// ���ƽ�����ͼƬ���ݵ�����
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
	TArray<FString> OpenFileNames;//��ȡ���ļ�����·��
	FString ExtensionStr = TEXT("*.*");//�ļ�����

	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	DesktopPlatform->OpenFileDialog(nullptr, TEXT("ywy�ļ�������"), FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()), TEXT(""), *ExtensionStr, EFileDialogFlags::None, OpenFileNames);
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
			// ��������
			UTexture2D* Texture = UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), PF_FloatRGBA);
			if (!Texture)
			{
				return nullptr;
			}

			// ���ƽ�����ͼƬ���ݵ�����
			FTexturePlatformData* PlatformData = Texture->GetPlatformData();
			void* TextureData = PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);

			// Debug: ��ӡUncompressedRGBA����Ĵ�С������
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
	//		// ��������
	//		UTexture2D* Texture = UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), PF_FloatRGBA);
	//		if (!Texture)
	//		{
	//			return nullptr;
	//		}

	//		// ���ƽ�����ͼƬ���ݵ�����
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

	//// ����һ���µ�UTexture2D���洢����
	//UTexture2D* Texture = UTexture2D::CreateTransient(RenderTarget->SizeX, RenderTarget->SizeY, RenderTarget->GetFormat());
	//if (!Texture) return nullptr;

	//FTexture2DMipMap& Mip = Texture->PlatformData->Mips[0];
	//void* Data = Mip.BulkData.Lock(LOCK_READ_WRITE);

	//// ����ȾĿ����Դ�ж�ȡ��������
	//TArray<FColor> OutBMP;
	//RenderTargetResource->ReadPixels(OutBMP);

	//// �����ݸ��Ƶ��µ�������
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
// ����������������ݸ��ƻ���ȾĿ��
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

	// ������д����ȾĿ��
	MaterialIns->SetTextureParameterValue(TEXT("texture"), Texture);
	UKismetRenderingLibrary::DrawMaterialToRenderTarget(WorldContextObject, RenderTarget, MaterialIns);
	MaterialIns->SetTextureParameterValue(TEXT("texture"), RenderTarget);
	/*FUpdateTextureRegion2D Region(0, 0, 0, 0, RenderTarget->SizeX, RenderTarget->SizeY);
	RenderTargetResource->UpdateTextureRegion(0, 1, &Region, RenderTarget->SizeX * sizeof(FColor), (uint32)sizeof(FColor), (uint8*)PixelData.GetData());*/
}

// ����Ҫ������Сʱ����
void MyTools::ResizeRenderTarget(UObject* WorldContextObject, UCanvasRenderTarget2D* RenderTarget, UMaterialInstanceDynamic* MaterialIns, int32 NewWidth, int32 NewHeight)
{
	if (!RenderTarget) 
		return;

	// ���Ƶ�ǰ���ݵ�һ������
	UTexture2D* TempTexture = CopyRenderTargetToTexture(RenderTarget);

	// ������ȾĿ���С
	RenderTarget->ResizeTarget(NewWidth, NewHeight);

	// �������ݻ���ȾĿ��
	CopyTextureToRenderTarget(WorldContextObject,RenderTarget, MaterialIns, TempTexture);

}