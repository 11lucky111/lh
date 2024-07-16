// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MySecondActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYSECONDPLUGIN_API UMySecondActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMySecondActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Overrides, meta = (PinHiddenByDefault, InlineEditConditionToggle))
	uint8 bOverride_Sharp : 1;
	UPROPERTY(interp, BlueprintReadWrite, Category = "Sharp", meta = (DisplayName = "Sharp", UIMin = "-1", UIMax = "1", editcondition = "bOverride_Sharp"))
	float Sharp = 0.0f;

private:
	void    TickSharp();
	UMaterialInstanceDynamic* CreateMaterial(FString assertName, FString instanceName);
	void    InitEncrypt(uint8* Key);
	void    AddBlendable(TScriptInterface<IBlendableInterface> InBlendableObject, float InWeight);
	FPostProcessSettings* QueryPostProcessSettings();
private:
	//sharp
	UPROPERTY()
	UMaterialInstanceDynamic* mSharpMaterial = nullptr;
	UPROPERTY()
	UMaterialInstanceDynamic* mBlurMaterial = nullptr;
	bool    mSharpEnabled = false;
	bool    mBlurEnabled = false;
	float   mCurSharpValue = 0;
	bool    mIsGlobal = true;
	uint8   mKey[32] = { 0 };
};
