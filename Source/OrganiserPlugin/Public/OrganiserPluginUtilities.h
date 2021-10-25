// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OrganiserPluginUtilities.generated.h"

/**
 * 
 */
UCLASS()
class ORGANISERPLUGIN_API UOrganiserPluginUtilities : public UObject
{
	GENERATED_BODY()
	
public:

	UOrganiserPluginUtilities();

	UFUNCTION()
	static void RemoveAllAssetsRefFree();

};
