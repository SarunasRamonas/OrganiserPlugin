// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OrganiserPlugin/Public/OrganiserPluginUtilities.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOrganiserPluginUtilities() {}
// Cross Module References
	ORGANISERPLUGIN_API UClass* Z_Construct_UClass_UOrganiserPluginUtilities_NoRegister();
	ORGANISERPLUGIN_API UClass* Z_Construct_UClass_UOrganiserPluginUtilities();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_OrganiserPlugin();
// End Cross Module References
	DEFINE_FUNCTION(UOrganiserPluginUtilities::execRemoveAllAssetsRefFree)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		UOrganiserPluginUtilities::RemoveAllAssetsRefFree();
		P_NATIVE_END;
	}
	void UOrganiserPluginUtilities::StaticRegisterNativesUOrganiserPluginUtilities()
	{
		UClass* Class = UOrganiserPluginUtilities::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "RemoveAllAssetsRefFree", &UOrganiserPluginUtilities::execRemoveAllAssetsRefFree },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOrganiserPluginUtilities_RemoveAllAssetsRefFree_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOrganiserPluginUtilities_RemoveAllAssetsRefFree_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OrganiserPluginUtilities.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UOrganiserPluginUtilities_RemoveAllAssetsRefFree_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOrganiserPluginUtilities, nullptr, "RemoveAllAssetsRefFree", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOrganiserPluginUtilities_RemoveAllAssetsRefFree_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOrganiserPluginUtilities_RemoveAllAssetsRefFree_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOrganiserPluginUtilities_RemoveAllAssetsRefFree()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UOrganiserPluginUtilities_RemoveAllAssetsRefFree_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UOrganiserPluginUtilities_NoRegister()
	{
		return UOrganiserPluginUtilities::StaticClass();
	}
	struct Z_Construct_UClass_UOrganiserPluginUtilities_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOrganiserPluginUtilities_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OrganiserPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UOrganiserPluginUtilities_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOrganiserPluginUtilities_RemoveAllAssetsRefFree, "RemoveAllAssetsRefFree" }, // 2430176729
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOrganiserPluginUtilities_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "OrganiserPluginUtilities.h" },
		{ "ModuleRelativePath", "Public/OrganiserPluginUtilities.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOrganiserPluginUtilities_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOrganiserPluginUtilities>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UOrganiserPluginUtilities_Statics::ClassParams = {
		&UOrganiserPluginUtilities::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UOrganiserPluginUtilities_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOrganiserPluginUtilities_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOrganiserPluginUtilities()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UOrganiserPluginUtilities_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UOrganiserPluginUtilities, 2136147558);
	template<> ORGANISERPLUGIN_API UClass* StaticClass<UOrganiserPluginUtilities>()
	{
		return UOrganiserPluginUtilities::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UOrganiserPluginUtilities(Z_Construct_UClass_UOrganiserPluginUtilities, &UOrganiserPluginUtilities::StaticClass, TEXT("/Script/OrganiserPlugin"), TEXT("UOrganiserPluginUtilities"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOrganiserPluginUtilities);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif