// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HAL/IConsoleManager.h"
#include "HAL/PlatformFilemanager.h"
#include "IPlatformFilePak.h"
#include "GenericPlatform/GenericPlatformFile.h"

#include "Windows/AllowWindowsPlatformTypes.h"
#include "Windows/PreWindowsApi.h"
#include <Windows.h>
#include "Windows/PostWindowsApi.h"
#include "Windows/HideWindowsPlatformTypes.h"

#include "MyActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPLUGIN_API UMyActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
    FPakPlatformFile* HandlePakPlatform;
	// Sets default values for this component's properties
	UMyActorComponent();
    virtual ~UMyActorComponent();
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Overrides, meta = (PinHiddenByDefault, InlineEditConditionToggle))
    uint8 bOverride_Lift : 1;
    UPROPERTY(interp, BlueprintReadWrite, Category = "Brightness", meta = (DisplayName = "Lift", UIMin = "-100", UIMax = "100", editcondition = "bOverride_Lift"))
    int Lift = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Overrides, meta = (PinHiddenByDefault, InlineEditConditionToggle))
    uint8 bOverride_Gamma : 1;
    UPROPERTY(interp, BlueprintReadWrite, Category = "Brightness", meta = (DisplayName = "Gamma", UIMin = "-100", UIMax = "100", editcondition = "bOverride_Gamma"))
    int Gamma = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Overrides, meta = (PinHiddenByDefault, InlineEditConditionToggle))
    uint8 bOverride_Gain : 1;
    UPROPERTY(interp, BlueprintReadWrite, Category = "Brightness", meta = (DisplayName = "Gain", UIMin = "-100", UIMax = "100", editcondition = "bOverride_Gain"))
    int Gain = 0;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    void    Update(float deltatime);
    //brightness
    bool    mBrightnessEnabled = false;
    bool    mIsGlobal = true;
    UMaterialInstanceDynamic* CreateMaterial(FString assertName, FString instanceName);
    void    AddBlendable(TScriptInterface<IBlendableInterface> InBlendableObject, float InWeight);
    FPostProcessSettings* QueryPostProcessSettings();
    UPROPERTY()
    UMaterialInstanceDynamic* mBrightnessMaterial = nullptr;
    uint8   mKey[32] = { 0 };
    void    InitEncrypt(uint8* key);
	void	TickBrightness();

};
