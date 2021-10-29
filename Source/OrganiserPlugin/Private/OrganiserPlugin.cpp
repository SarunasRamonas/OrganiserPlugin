// Copyright Epic Games, Inc. All Rights Reserved.

#include "OrganiserPlugin.h"
#include "OrganiserPluginStyle.h"
#include "OrganiserPluginCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"
#include "OrganiserPluginUtilities.h"

static const FName OrganiserPluginTabName("OrganiserPlugin");

#define LOCTEXT_NAMESPACE "FOrganiserPluginModule"

void FOrganiserPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FOrganiserPluginStyle::Initialize();
	FOrganiserPluginStyle::ReloadTextures();

	FOrganiserPluginCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FOrganiserPluginCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FOrganiserPluginModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FOrganiserPluginModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(OrganiserPluginTabName, FOnSpawnTab::CreateRaw(this, &FOrganiserPluginModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FOrganiserPluginTabTitle", "OrganiserPlugin"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FOrganiserPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FOrganiserPluginStyle::Shutdown();

	FOrganiserPluginCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(OrganiserPluginTabName);
}

TSharedRef<SDockTab> FOrganiserPluginModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FOrganiserPluginModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("OrganiserPlugin.cpp"))
		);

	const FMargin ButtonPadding = FMargin(10.f);
	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 14.f;


	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			
			[
				SNew(SVerticalBox)

				/*
				 * ------- Create Folder Structure button with text -------
				 */
				+ SVerticalBox::Slot()
					.Padding(FMargin(20.0f, 20.0f, 20.0f, 20.0f))
					.VAlign(VAlign_Center)
					.AutoHeight()
					[
						SNew(SButton)
						.OnClicked_Raw(this, &FOrganiserPluginModule::OnCreateFolderStructureClicked)
					[
						SNew(STextBlock)
						.Font(ButtonTextStyle)
					.Text(FText::FromString("Create Top Level Folder Structure"))
					.Justification(ETextJustify::Center)
					]
					]



				/*
				 * ------- Fix button with text -------
				 */
				+ SVerticalBox::Slot()
					.Padding(FMargin(20.0f, 20.0f, 20.0f, 20.0f))
					.VAlign(VAlign_Center)
					.AutoHeight()
					[
						SNew(SButton)
						.OnClicked_Raw(this, &FOrganiserPluginModule::OnCleanupButtonClicked)
					[
						SNew(STextBlock)
						.Font(ButtonTextStyle)
						.Text(FText::FromString("Fix"))
						.Justification(ETextJustify::Center)
					]
					]
				

			]
				
		];
}


FReply FOrganiserPluginModule::OnCleanupButtonClicked()
{
	UOrganiserPluginUtilities::MakeOrganizationDir();
	return FReply::Handled();
}

FReply FOrganiserPluginModule::OnCreateFolderStructureClicked()
{
	TArray<FString> TopLevelFoldersNames;
	TopLevelFoldersNames.Add("Art");
	TopLevelFoldersNames.Add("Core");
	TopLevelFoldersNames.Add("Maps");
	TopLevelFoldersNames.Add("MaterialLibrary");
	UOrganiserPluginUtilities::CreateContenctTopLevelStructure(TopLevelFoldersNames);
	return FReply::Handled();
}

void FOrganiserPluginModule::PluginButtonClicked()
{
	
	FGlobalTabmanager::Get()->TryInvokeTab(OrganiserPluginTabName);
}

void FOrganiserPluginModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FOrganiserPluginCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FOrganiserPluginCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FOrganiserPluginModule, OrganiserPlugin)