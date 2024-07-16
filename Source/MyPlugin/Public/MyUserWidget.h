// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/Image.h>
#include <Components/Button.h>
#include <Engine/CanvasRenderTarget2D.h>
#include "Input/Events.h"

#include "MyUserWidget.generated.h"




/**
 * 
 */
UCLASS()
class MYPLUGIN_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent);
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent);
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RenderTarget")
	UCanvasRenderTarget2D* CanvasRenderTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Path")
	FString mImagePath;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Paint")
	FVector2D StartPoint;

private:
	UPROPERTY(meta = (BindWidget))
		UImage* imageView;
	UPROPERTY(meta = (BindWidget))
		UButton* LoadImageButton;
	UPROPERTY(meta = (BindWidget))
		UButton* SaveImageButton;
	UFUNCTION()
		void OnLoadImageButtonClick();
	UFUNCTION()
		void OnSaveImageButtonClick();
private:
	void StartPaint(FVector2D LastPosition, FVector2D CurrentPosition, float Thickness, FLinearColor RenderColor);
	void OnViewportResize(FViewport* ViewPort, uint32 val);

private:
	bool MouseDown = false;
	bool first = true;//防止开始时绘制错误的线
	bool MouseEnterWindow = true;
	bool MouseLeaveWindow = true;
	bool ViewportSizeIsChange = false;
	int8 once = 0;
	FVector2D ScreenSpacePosition{ 0, 0 };
	FIntPoint ViewportSize{ 0, 0 }, TextureSize{ 0, 0 }, CurViewportSize{ 0, 0 };
	TArray<FColor> TextureColor;
	UMaterialInstanceDynamic* MyMaterialIns = nullptr; 

};
