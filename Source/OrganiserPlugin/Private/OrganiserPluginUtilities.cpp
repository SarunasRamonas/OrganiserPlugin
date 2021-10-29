// Fill out your copyright notice in the Description page of Project Settings.


#include "OrganiserPluginUtilities.h"
#include "EditorAssetLibrary.h"
#include "AssetToolsModule.h"

UOrganiserPluginUtilities::UOrganiserPluginUtilities()
{
}

void UOrganiserPluginUtilities::RemoveAllAssetsRefFree()
{
	TArray<FString> allAssets = UEditorAssetLibrary::ListAssets(GetDirectory(), true, false);
	for (int i = 0; i < allAssets.Num(); i++)
	{
		TArray<FString> assetRefs = UEditorAssetLibrary::FindPackageReferencersForAsset(allAssets[i], false);
		if (assetRefs.Num() <= 0)
		{
			UEditorAssetLibrary::DeleteAsset(allAssets[i]);
		}
	}
}

void UOrganiserPluginUtilities::RemoveAllEmptyFolders()
{

}

void UOrganiserPluginUtilities::UnifyAssetsDuplicates()
{
	const FString dirPath = "/Game/";
	TArray<FString> allAssets = UEditorAssetLibrary::ListAssets(dirPath, true, true);

	for (int i = 0; i < allAssets.Num(); i++)
	{
		FAssetData assetData = UEditorAssetLibrary::FindAssetData(allAssets[i]);
		UObject* asset = assetData.GetAsset();
		FName assetName = assetData.AssetName;
		FName assetPath = assetData.PackagePath;

		TArray <UObject*> assetMatching;
		//assetMatching.Empty();

		for (int x = 0; x < allAssets.Num(); x++)
		{
			if (UEditorAssetLibrary::FindAssetData(allAssets[x]).AssetName == assetName )
			{
				if (allAssets[x] != assetPath.ToString())
				{
					UEditorAssetLibrary::LoadAsset(allAssets[x]);
					assetMatching.Add(UEditorAssetLibrary::FindAssetData(allAssets[x]).GetAsset());
				}
			}
		}

		if (assetMatching.Num() != 0)
		{
			UEditorAssetLibrary::ConsolidateAssets(asset,assetMatching);
		}
	}
}

void UOrganiserPluginUtilities::MakeOrganizationDir()
{
	const FString dirPath = "/Game/";
	TArray<FString> allAssets = UEditorAssetLibrary::ListAssets(dirPath, true, false);

	/*
	for (int i = 0; i < allAssets.Num(); i++)
	{
		FAssetData assetData = UEditorAssetLibrary::FindAssetData(allAssets[i]);
		UObject* asset = assetData.GetAsset();
		FName assetName = assetData.AssetName;
		FString assetPathName = assetData.GetAsset()->GetPathName();

		FString assetClassName = asset->GetName();
		FString targetPathName = ("/Game/" + assetClassName + "/" + assetName.ToString() + "." + assetName.ToString());

		UEditorAssetLibrary::RenameAsset(assetPathName, targetPathName);

		UE_LOG(LogTemp, Warning, TEXT("Function finished job"));
	}
	*/

	CreateDirectory(dirPath + "Art");
}


bool UOrganiserPluginUtilities::CreateDirectory(FString DirectoryPath)
{
	if (UEditorAssetLibrary::CheckoutDirectory(DirectoryPath))
	{
		return UEditorAssetLibrary::MakeDirectory(DirectoryPath);
	}
	else
	{
		return false;
	}	
}

bool UOrganiserPluginUtilities::FixUpAllRedirectors()
{
	const TArray<UObjectRedirector*>AllFoundRedirectors;
	if (AllFoundRedirectors.Num() != 0)
	{
		FAssetToolsModule& AssetToolModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>(TEXT("AssetTools"));
		AssetToolModule.Get().FixupReferencers(AllFoundRedirectors);
		return true;
	}
	else
	{
		return false;
	}
}

bool UOrganiserPluginUtilities::CreateContenctTopLevelStructure(TArray<FString> FolderNames)
{
	for (int i = 0; i < FolderNames.Num(); i++)
	{
		CreateDirectory(FString(GetDirectory() + FolderNames[i]));
	}
	return true;
}
