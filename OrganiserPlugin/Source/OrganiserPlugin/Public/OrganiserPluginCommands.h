// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "OrganiserPluginStyle.h"

class FOrganiserPluginCommands : public TCommands<FOrganiserPluginCommands>
{
public:

	FOrganiserPluginCommands()
		: TCommands<FOrganiserPluginCommands>(TEXT("OrganiserPlugin"), NSLOCTEXT("Contexts", "OrganiserPlugin", "OrganiserPlugin Plugin"), NAME_None, FOrganiserPluginStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};