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

	/*
	 * Removes all assets in content browser, which has no references.
	 * @note:
	 */
	UFUNCTION()
	static void RemoveAllAssetsRefFree();

	UFUNCTION()
	static void RemoveAllEmptyFolders();

	UFUNCTION()
	static void UnifyAssetsDuplicates();

	UFUNCTION()
	static void MakeOrganizationDir();


private:

	static bool CreateDirectory(FString DirectoryPath);
};
