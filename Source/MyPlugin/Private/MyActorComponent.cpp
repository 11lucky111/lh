// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorComponent.h"
#include <Camera/CameraActor.h>
#include <Engine/PostProcessVolume.h>
#include <Camera/CameraComponent.h>
#include "HAL/PlatformFilemanager.h"
#include "IPlatformFilePak.h"

#include "Windows/AllowWindowsPlatformTypes.h"
#include "Windows/PreWindowsApi.h"
#include <Windows.h>
#include "Windows/PostWindowsApi.h"
#include "Windows/HideWindowsPlatformTypes.h"
// Sets default values for this component's properties
UMyActorComponent::UMyActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = true;
    PrimaryComponentTick.TickGroup = TG_PrePhysics;

    bAutoRegister = true;
    bWantsInitializeComponent = true;
    bAutoActivate = true;
    bIsEditorOnly = false;
    bTickInEditor = true;

    mKey[0] = 107;
    mKey[1] = 128;
    mKey[2] = 146;
    mKey[3] = 185;
    mKey[4] = 198;
    mKey[5] = 87;
    mKey[6] = 109;
    mKey[7] = 22;
    mKey[8] = 253;
    mKey[9] = 254;
    mKey[10] = 108;
    mKey[11] = 238;
    mKey[12] = 56;
    mKey[13] = 87;
    mKey[14] = 237;
    mKey[15] = 124;
    mKey[16] = 1;
    mKey[17] = 177;
    mKey[18] = 115;
    mKey[19] = 51;
    mKey[20] = 121;
    mKey[21] = 71;
    mKey[22] = 59;
    mKey[23] = 88;
    mKey[24] = 23;
    mKey[25] = 74;
    mKey[26] = 12;
    mKey[27] = 102;
    mKey[28] = 77;
    mKey[29] = 175;
    mKey[30] = 132;
    mKey[31] = 249;
	// ...
}

UMyActorComponent::~UMyActorComponent()
{
}


// Called when the game starts
void UMyActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    if (bRegistered && !IsBeingDestroyed()) {
        Update(DeltaTime);
    }
	// ...
}

void UMyActorComponent::Update(float deltatime)
{

    TickBrightness();
}

UMaterialInstanceDynamic* UMyActorComponent::CreateMaterial(FString assertName, FString instanceName)
{
    static bool useClearMatInterface = false;
    static bool useMatInterfaceInEditor = true;

    bool useMatInterface = true;
#if WITH_EDITOR
    if (GIsEditor)
    {
        useMatInterface = useMatInterfaceInEditor;
    }
#endif
    UMaterialInstanceDynamic* uMat = nullptr;
    if (useClearMatInterface) {
        FString assertPath = TEXT("/MyPlugin/") + assertName + (mIsGlobal ? "Global." : ".") + assertName;
        UMaterialInterface* MaterialInterface = LoadObject<UMaterialInterface>(nullptr, *assertPath, nullptr, LOAD_None, nullptr);
        if (MaterialInterface) {
            //uMat = UMaterialInstanceDynamic::Create(MaterialInterface, NULL, FName(instanceName));
            uMat = UMaterialInstanceDynamic::Create(MaterialInterface, NULL);

        }
    }
    else if (useMatInterface) {
        IPlatformFile* PlatformFile = &FPlatformFileManager::Get().GetPlatformFile();
        //FPakPlatformFile* PakPlatformFile = new FPakPlatformFile();
        TSharedPtr<FPakPlatformFile> PakPlatformFile = MakeShareable(new FPakPlatformFile());
        bool ret = PakPlatformFile->Initialize(PlatformFile, TEXT(""));
        if (ret) {
            FCoreDelegates::GetPakEncryptionKeyDelegate().BindUObject(this, &UMyActorComponent::InitEncrypt);
            FPlatformFileManager::Get().SetPlatformFile(*PakPlatformFile);
            FString PakFileName = FPaths::ConvertRelativePathToFull(FPaths::ProjectPluginsDir()) / TEXT("MyPlugin/Content/ZRealRender.pak");
            FString PakMountPoint = FPaths::ConvertRelativePathToFull(FPaths::ProjectPluginsDir()) / TEXT("MyPlugin/Content");
            ret = PakPlatformFile->Mount(*PakFileName, 1000, *PakMountPoint);
            if (!ret) {
                UE_LOG(LogTemp, Warning, TEXT("CreateMaterial for %s,FPakPlatformFile Mount failed"), *assertName);
            }
            FString assertPath = TEXT("/MyPlugin/") + assertName + (mIsGlobal ? "Global." : ".") + assertName;

            //assertPath: / MyPlugin / ZRealBrightnessMaterialGlobal.ZRealBrightnessMaterial
            UMaterialInterface* MaterialInterface = LoadObject<UMaterialInterface>(nullptr, *assertPath, nullptr, LOAD_None, nullptr);
            if (MaterialInterface) {
                //static int id = 0;
                //FString name = instanceName + std::to_string(id++).c_str();
                uMat = UMaterialInstanceDynamic::Create(MaterialInterface, NULL, FName(instanceName));
                //uMat = UMaterialInstanceDynamic::Create(MaterialInterface, NULL);
            }
            else {
                UE_LOG(LogTemp, Warning, TEXT("CreateMaterial for %s, interface load failed"), *assertName);
            }
            //resotre
            if (PlatformFile) {
                FPlatformFileManager::Get().SetPlatformFile(*PlatformFile);
            }
        }
        else {
            UE_LOG(LogTemp, Warning, TEXT("CreateMaterial for %s, FPakPlatformFile Initialize failed"), *assertName);
        }
    }
    else {
        uMat = UMaterialInstanceDynamic::Create(nullptr, nullptr, FName(instanceName));
    }
    return uMat;
}

void UMyActorComponent::AddBlendable(TScriptInterface<IBlendableInterface> InBlendableObject, float InWeight)
{
    static FCriticalSection DataGuard;
    FScopeLock Lock(&DataGuard);
    FPostProcessSettings* pSettings = QueryPostProcessSettings();
    if (pSettings) {
        if (UObject* Object = InBlendableObject.GetObject())
        {
            for (int32 i = 0, count = pSettings->WeightedBlendables.Array.Num(); i < count; ++i)
            {
                if (pSettings->WeightedBlendables.Array[i].Object == Object)
                {
                    pSettings->WeightedBlendables.Array[i].Weight = InWeight;
                    if (InWeight == 0) {
                        pSettings->WeightedBlendables.Array[i].Object = nullptr;
                    }
                    return;
                }
            }
            for (int32 i = 0, count = pSettings->WeightedBlendables.Array.Num(); i < count; ++i)
            {
                if (pSettings->WeightedBlendables.Array[i].Object == nullptr)
                {
                    pSettings->WeightedBlendables.Array[i].Object = Object;
                    pSettings->WeightedBlendables.Array[i].Weight = InWeight;
                    return;
                }
            }
            if (InWeight > 0) {
                pSettings->WeightedBlendables.Array.Add(FWeightedBlendable(InWeight, Object));
            }
        }
    }
}

FPostProcessSettings* UMyActorComponent::QueryPostProcessSettings()
{
    FPostProcessSettings* pSettings = nullptr;
    AActor* pActor = GetOwner();
    if (pActor) {
        if (pActor->IsA(ACameraActor::StaticClass())) {
            UCameraComponent* pComCamera = pActor->FindComponentByClass<UCameraComponent>();
            if (pComCamera != nullptr) {
                pSettings = &pComCamera->PostProcessSettings;
            }
        }
        else if (pActor->IsA(APostProcessVolume::StaticClass())) {
            APostProcessVolume* pPostProcessVolume = Cast<APostProcessVolume>(pActor);
            if (pPostProcessVolume) {
                pSettings = &pPostProcessVolume->Settings;
            }
        }
    }
    return pSettings;
}

void UMyActorComponent::InitEncrypt(uint8* key)
{
    FMemory::Memcpy(key, mKey, FAES::FAESKey::KeySize);
}

void UMyActorComponent::TickBrightness()
{
    bool enable = (bOverride_Lift == 1 || bOverride_Gamma == 1 || bOverride_Gain == 1);
    if (!mBrightnessEnabled && !enable) {
        return;
    }
    if (mBrightnessMaterial == nullptr) {
        mBrightnessMaterial = CreateMaterial("ZRealBrightnessMaterial", "brightness");
    }
    if (mBrightnessMaterial) {

        float flift = bOverride_Lift == 1 ? Lift : 0;
        flift = flift >= 0 ? flift / 200 : flift / 100;
        float lift_px = -flift * 255.0 / (1 - flift);

        float fgain = bOverride_Gain == 1 ? Gain : 0;
        fgain = fgain >= 0 ? fgain / 100.0 + 1.0 : fgain / 200.0 + 1.0;
        float gain_px = 255.0 / fgain;

        float fgamma = bOverride_Gamma == 1 ? Gamma : 0;
        fgamma = fgamma >= 0 ? 1.0 - fgamma / 200.0 : 1.0 - fgamma / 100.0;

        mBrightnessMaterial->SetScalarParameterValue(FName(TEXT("lift")), lift_px);
        mBrightnessMaterial->SetScalarParameterValue(FName(TEXT("gamma")), fgamma);
        mBrightnessMaterial->SetScalarParameterValue(FName(TEXT("gain")), gain_px);

        if (enable && !mBrightnessEnabled) {
            AddBlendable(mBrightnessMaterial, 1.0f);
            mBrightnessEnabled = true;
        }
        if (!enable && mBrightnessEnabled) {
            AddBlendable(mBrightnessMaterial, 0.0f);
            //pSettings->RemoveBlendable(mBrightnessMaterial);
            mBrightnessEnabled = false;
        }
    }
}

