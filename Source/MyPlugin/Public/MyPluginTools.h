// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MYPLUGIN_API MyPluginTools
{
public:
	MyPluginTools();
	~MyPluginTools();
public:
	static UTexture2D* LoadTextureFromDisk(const FString& ImagePath);

};
