// Copyright Epic Games, Inc. All Rights Reserved.

#include "MySecondPluginBPLibrary.h"
#include "MySecondPlugin.h"

UMySecondPluginBPLibrary::UMySecondPluginBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UMySecondPluginBPLibrary::MySecondPluginSampleFunction(float Param)
{
	return -1;
}

