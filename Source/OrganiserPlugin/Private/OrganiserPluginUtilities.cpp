// Fill out your copyright notice in the Description page of Project Settings.


#include "OrganiserPluginUtilities.h"
#include "EditorAssetLibrary.h"

UOrganiserPluginUtilities::UOrganiserPluginUtilities()
{

}

void UOrganiserPluginUtilities::RemoveAllAssetsRefFree()
{
	const FString dirPath = "/Game/";
	TArray<FString> allAssets = UEditorAssetLibrary::ListAssets(dirPath, true, false);

	for (int i = 0; i < allAssets.Num(); i++)
	{
		TArray<FString> assetRefs = UEditorAssetLibrary::FindPackageReferencersForAsset(allAssets[i], false);
		if (assetRefs.Num() <= 0)
		{
			UEditorAssetLibrary::DeleteAsset(allAssets[i]);
		}
	}
}
