// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyPluginBPLibrary.h"
#include "MyPlugin.h"

UMyPluginBPLibrary::UMyPluginBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UMyPluginBPLibrary::MyPluginSampleFunction(float Param)
{
	return -1;
}

