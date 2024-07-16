// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <MyUserWidget.h>

#include "MyPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class MYPLUGIN_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMyPlayerController();
	virtual void BeginPlay() override;
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UMyUserWidget> mMyUserWidgetClass;
	UMyUserWidget* mMyUserWidget = nullptr;
};
