// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"
#include "MyTools.h"
#include "MyActor.h"
#include <Kismet/GameplayStatics.h>
#include "Kismet/KismetRenderingLibrary.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Engine/Canvas.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/CanvasPanelSlot.h"
void UMyUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//视口变化时回调OnViewportResize
	GEngine->GameViewport->Viewport->ViewportResizedEvent.AddUObject(this, &UMyUserWidget::OnViewportResize);

	if (LoadImageButton)
	{
		LoadImageButton->OnClicked.__Internal_AddDynamic(this, &UMyUserWidget::OnLoadImageButtonClick, FName("OnLoadImageButtonClick"));
		SaveImageButton->OnClicked.__Internal_AddDynamic(this, &UMyUserWidget::OnLoadImageButtonClick, FName("OnSaveImageButtonClick"));

	}
	if (UCanvasPanelSlot* imageViewSlot = Cast<UCanvasPanelSlot>(imageView->Slot))
	{
		//imageViewSlot->LayoutData.Anchors.Minimum = FVector2D(0.0f,0.0f);
		imageViewSlot->SetAnchors(FAnchors(0, 0, 1, 1));
		imageViewSlot->SetOffsets(FMargin(0, 0, 0, 0));
		//imageViewSlot->SetSize(FVector2D{186, 163});
	}
}

void UMyUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	//UE_LOG(LogTemp,Warning,TEXT("%d"), MouseDown);
	if (once == 0)
		if (MouseDown && !TextureColor.IsEmpty())
		{
			Super::NativeTick(MyGeometry, InDeltaTime);
			return;
			////位置不准确
			//FVector2D MousePosition = UWidgetLayoutLibrary::GetMousePositionOnViewport(GetWorld());

			FVector2D MousePosition;
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetMousePosition(MousePosition.X, MousePosition.Y);
			if (ViewportSizeIsChange)
			{
				if (MousePosition.X > CurViewportSize.X || MousePosition.Y > CurViewportSize.Y)
				{
					return;
				}
				//UE_LOG(LogTemp, Warning, TEXT("%f,%f,%d,%d"), MousePosition.X, MousePosition.Y, CurViewportSize.X, CurViewportSize.Y);
				MousePosition.X = MousePosition.X / CurViewportSize.X * ViewportSize.X;
				MousePosition.Y = MousePosition.Y / CurViewportSize.Y * ViewportSize.Y;
			}
			else
			{
				CurViewportSize = ViewportSize;
				if (MousePosition.X > ViewportSize.X || MousePosition.Y > ViewportSize.Y)
				{
					return;
				}
			}

			//UE_LOG(LogTemp, Warning, TEXT("after:%f,%f"), MousePosition.X, MousePosition.Y);
			//UE_LOG(LogTemp, Warning, TEXT("%f,%f,%d,%d,%f,%f"), MousePosition.X, MousePosition.Y, ViewportSize.X, ViewportSize.Y, MousePosition.Y /  ViewportSize.Y, floor(MousePosition.X / ViewportSize.X * TextureSize.X));

			int32 idx = floor(MousePosition.Y / ViewportSize.Y * TextureSize.Y) * TextureSize.X + floor(MousePosition.X / ViewportSize.X * TextureSize.X);
			FColor MousePointColor = TextureColor[idx];

			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Cyan, FString::Printf(TEXT("index      :%d,%s"), idx, *MousePointColor.ToString()));
			////屏幕颜色最后都变成画笔颜色
			//FColor ScreenMousePointColor = MyTools::GetMousePointColor();
			//GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Cyan, FString::Printf(TEXT("screenindex:%d,%s"), idx, *ScreenMousePointColor.ToString()));

			////相对位置，但由于需要FPointerEvent InMouseEvent无法使用
			//FGeometry Geometry = imageView->GetCachedGeometry();
			//MousePosition = Geometry.AbsoluteToLocal(ScreenSpacePosition);

			//防止第一次错画
			if (first || MouseEnterWindow || MouseLeaveWindow)
			{
				StartPoint = MousePosition;
				first = false;
				MouseEnterWindow = false;
				MouseLeaveWindow = false;
			}

			//StartPaint(StartPoint, MousePosition, 5, FLinearColor(1.0f, 0.0f, 0.0f, 1.0f));
			StartPoint = MousePosition;
		}

}

FReply UMyUserWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	//ScreenSpacePosition = InMouseEvent.GetScreenSpacePosition();
	UE_LOG(LogTemp, Warning, TEXT("ButtonDown"));
	MouseDown = true;


	return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}

FReply UMyUserWidget::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	UE_LOG(LogTemp, Warning, TEXT("ButtonUp"));
	MouseDown = false;
	first = true;
	return Super::NativeOnMouseButtonUp(InGeometry, InMouseEvent);
}

void UMyUserWidget::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);
	MouseLeaveWindow = true;
}

void UMyUserWidget::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);
	MouseEnterWindow = true;
}

void UMyUserWidget::OnLoadImageButtonClick()
{

	ViewportSize = GetWorld()->GetGameViewport()->Viewport->GetSizeXY();
	CanvasRenderTarget = UCanvasRenderTarget2D::CreateCanvasRenderTarget2D(GEngine->GetWorld(), UCanvasRenderTarget2D::StaticClass(), ViewportSize.X, ViewportSize.Y);
	//CanvasRenderTarget->RenderTargetFormat = 
	TArray<FString> StringArray = MyTools::OpenWindowsFiles();
	if (StringArray.IsEmpty())
	{
		return;
	}
	UTexture2D* MyTexture = MyTools::LoadTextureFromDisk(StringArray[0]);
	TextureColor = MyTools::GetPictureRGBPixel(MyTexture, TextureSize.X, TextureSize.Y, false);
	/*imageView->SetBrushFromTexture(MyTexture);*/
	//imageView->SetBrushSize(FVector2D{186, 163});

	//创建材质，并根据所选图片替换纹理
	MyMaterialIns = MyTools::CreateMaterial("MyMaterial", "MyMaterialIns");
	MyMaterialIns->SetTextureParameterValue(TEXT("texture"), MyTexture);

	//按Tag获取actor
	TArray<AActor*> MyActorArray;
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), AMyActor::StaticClass(), TEXT("MyActorTag"), MyActorArray);
	for (AActor* MyActor : MyActorArray)
	{
		AMyActor* AMyActorCast = Cast<AMyActor>(MyActor);
		if (AMyActorCast)
		{

			AMyActorCast->StaticMesh->SetMaterial(0, MyMaterialIns);

		}
	}

	//将材质绘制到创建的canvas render target 2D
	UKismetRenderingLibrary::DrawMaterialToRenderTarget(GetWorld(), CanvasRenderTarget, MyMaterialIns);
	MyMaterialIns->SetTextureParameterValue(TEXT("texture"), CanvasRenderTarget);
	imageView->SetBrushFromMaterial(MyMaterialIns);
}

void UMyUserWidget::OnSaveImageButtonClick()
{
	UKismetRenderingLibrary::ExportRenderTarget(GetWorld(), CanvasRenderTarget, "C:\\Users\\zreal\\Desktop", "MyRender");
}

void UMyUserWidget::StartPaint(FVector2D LastPosition, FVector2D CurrentPosition, float Thickness, FLinearColor RenderColor)
{
	UCanvas* Canvas = nullptr;
	FVector2D Vector2D;
	FDrawToRenderTargetContext DrawToRenderTargetContext;
	UKismetRenderingLibrary::BeginDrawCanvasToRenderTarget(GetWorld(), CanvasRenderTarget, Canvas, Vector2D, DrawToRenderTargetContext);
	Canvas->K2_DrawLine(LastPosition, CurrentPosition, Thickness, RenderColor);
	UKismetRenderingLibrary::EndDrawCanvasToRenderTarget(GetWorld(), DrawToRenderTargetContext);
}

void UMyUserWidget::OnViewportResize(FViewport* ViewPort, uint32 val)
{

	//if (once == 0)
	//{
	//	once++;
	//	//ViewportSize = FIntPoint(800,600);
	//	/*MyTools::ResizeRenderTarget(GetWorld(),CanvasRenderTarget,MyMaterialIns,ViewportSize.X,ViewportSize.Y);*/
	//	UTexture2D* TEX = MyTools::CopyRenderTargetToTexture(CanvasRenderTarget);
	//	FIntPoint TextureSize1{ 0,0 };
	//	TArray<FLinearColor> TextureColor1 = MyTools::GetPictureRGBAPixel(TEX, TextureSize1.X, TextureSize1.Y, true);
	//	//for (FColor &q:TextureColor1)
	//	//{
	//	//	UE_LOG(LogTemp, Warning, TEXT("%s"),*q.ToString());
	//	//}
	//	TArray<FColor> TextureColor2 = MyTools::GetRenderTargetPixelData(CanvasRenderTarget, TextureSize1.X, TextureSize1.Y);
	//	MyMaterialIns->SetTextureParameterValue(TEXT("texture"), TEX);
	//	imageView->SetBrushFromTexture(TEX);
	//	UE_LOG(LogTemp, Warning, TEXT("111"));
	//}

	if (GetWorld()->GetGameViewport())
	{
		CurViewportSize = GetWorld()->GetGameViewport()->Viewport->GetSizeXY();
		ViewportSizeIsChange = true;
	}

}
