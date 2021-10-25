// Copyright Epic Games, Inc. All Rights Reserved.

#include "OrganiserPluginCommands.h"

#define LOCTEXT_NAMESPACE "FOrganiserPluginModule"

void FOrganiserPluginCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "OrganiserPlugin", "Bring up OrganiserPlugin window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
