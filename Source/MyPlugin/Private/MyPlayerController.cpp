// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "MyActor.h"
#include "GameFramework/GameUserSettings.h"
AMyPlayerController::AMyPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
	static int8 cnt = 0;
	++cnt;
	UE_LOG(LogTemp, Warning, TEXT("CNT:%d"), cnt);
	static ConstructorHelpers::FClassFinder<UMyUserWidget> MyUserWidgetClassFinder(TEXT("/MyPlugin/MyUserWidget.MyUserWidget_C"));
	if (MyUserWidgetClassFinder.Succeeded())
	{
		mMyUserWidgetClass = MyUserWidgetClassFinder.Class;
	}
}

void AMyPlayerController::BeginPlay()
{
	GEngine->GetGameUserSettings()->SetFullscreenMode(EWindowMode::Windowed);
	GEngine->GetGameUserSettings()->SetScreenResolution(FIntPoint(1920, 1080));
	GEngine->GetGameUserSettings()->ApplySettings(true);

	bShowMouseCursor = true;
	if (mMyUserWidgetClass)
	{
		mMyUserWidget = CreateWidget<UMyUserWidget>(this,mMyUserWidgetClass);
		if (mMyUserWidget)
		{
			mMyUserWidget->AddToViewport();
		}
	}
	FVector SpawnActorLocation(0,0,0);
	FRotator SpawnActorRotation(0,0,0);
	GetWorld()->SpawnActor<AMyActor>(SpawnActorLocation, SpawnActorRotation);
}
