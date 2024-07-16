// Fill out your copyright notice in the Description page of Project Settings.


#include "MySecondActorComponent.h"
#include <IPlatformFilePak.h>
#include <Camera/CameraActor.h>
#include <Camera/CameraComponent.h>
#include <Engine/PostProcessVolume.h>

// Sets default values for this component's properties
UMySecondActorComponent::UMySecondActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;
    //PrimaryComponentTick.bStartWithTickEnabled = true;
    //PrimaryComponentTick.TickGroup = TG_PrePhysics;

    //bAutoRegister = true;
    //bWantsInitializeComponent = true;
    //bAutoActivate = true;
    //bIsEditorOnly = false;
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


// Called when the game starts
void UMySecondActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMySecondActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    TickSharp();
	// ...
}

void UMySecondActorComponent::TickSharp()
{
    if (!mSharpEnabled && !mBlurEnabled && bOverride_Sharp == 0) {
        return;
    }
    if (bOverride_Sharp > 0 && Sharp > 0 && mSharpMaterial == nullptr) {
        mSharpMaterial = CreateMaterial("ZRealSharpenMaterial", "sharp");
    }
    if (bOverride_Sharp > 0 && Sharp < 0 && mBlurMaterial == nullptr) {
        mBlurMaterial = CreateMaterial("ZRealBlurMaterial", "blur");
    }

    if (bOverride_Sharp == 1) {
        static float scalar = 1.0f;
        float value = Sharp * scalar;
        if (mCurSharpValue != value) {
            //UE_LOG(LogTemp, Warning, TEXT("UZRealPostProcessComponent::TickSharp mSharpMaterial= %p this=%p key=%s, value=%f size=%d"), mSharpMaterial, this, *mParamSharpen.ToString(), value, mSharpMaterial->ScalarParameterValues.Num());
            if (mSharpMaterial) {
                mSharpMaterial->SetScalarParameterValue("sharpen", value > 0 ? value : 0);
            }
            if (mBlurMaterial) {
                mBlurMaterial->SetScalarParameterValue("ratio", value < 0 ? (-value) : 0);
            }
            mCurSharpValue = value;
        }
    }

    //sharp
    if (bOverride_Sharp == 1 && Sharp > 0 && !mSharpEnabled && mSharpMaterial) {
        AddBlendable(mSharpMaterial, 1.0f);
        mSharpEnabled = true;
    }
    if ((bOverride_Sharp == 0) && mSharpEnabled && mSharpMaterial) {
        AddBlendable(mSharpMaterial, 0.0f);
        //pSettings->RemoveBlendable(mSharpMaterial);
        mSharpEnabled = false;
    }

    //blur
    if (bOverride_Sharp == 1 && Sharp < 0 && !mBlurEnabled && mBlurMaterial) {
        AddBlendable(mBlurMaterial, 1.0f);
        mBlurEnabled = true;
    }
    if ((bOverride_Sharp == 0) && mBlurEnabled && mBlurMaterial) {
        AddBlendable(mBlurMaterial, 0.0f);
        //pSettings->RemoveBlendable(mBlurMaterial);
        mBlurEnabled = false;
    }
}

UMaterialInstanceDynamic* UMySecondActorComponent::CreateMaterial(FString assertName, FString instanceName)
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
        TSharedPtr<FPakPlatformFile> PakPlatformFile = MakeShareable(new FPakPlatformFile());
        bool ret = PakPlatformFile->Initialize(PlatformFile, TEXT(""));
        if (ret) {
            FCoreDelegates::GetPakEncryptionKeyDelegate().BindUObject(this, &UMySecondActorComponent::InitEncrypt);
            FPlatformFileManager::Get().SetPlatformFile(*PakPlatformFile);
            FString PakFileName = FPaths::ConvertRelativePathToFull(FPaths::ProjectPluginsDir()) / TEXT("MyPlugin/Content/ZRealRender.pak");
            FString PakMountPoint = FPaths::ConvertRelativePathToFull(FPaths::ProjectPluginsDir()) / TEXT("MyPlugin/Content");
            ret = PakPlatformFile->Mount(*PakFileName, 1000, *PakMountPoint);
            if (!ret) {
                UE_LOG(LogTemp, Warning, TEXT("CreateMaterial for %s,FPakPlatformFile Mount failed"), *assertName);
            }
            FString assertPath = TEXT("/MyPlugin/") + assertName + (mIsGlobal ? "Global." : ".") + assertName;
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

void UMySecondActorComponent::InitEncrypt(uint8* key)
{
    FMemory::Memcpy(key, mKey, FAES::FAESKey::KeySize);
}

void UMySecondActorComponent::AddBlendable(TScriptInterface<IBlendableInterface> InBlendableObject, float InWeight)
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

FPostProcessSettings* UMySecondActorComponent::QueryPostProcessSettings()
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

