// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TestUnrealEngine/TestUnrealEngineGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTestUnrealEngineGameModeBase() {}
// Cross Module References
	TESTUNREALENGINE_API UClass* Z_Construct_UClass_ATestUnrealEngineGameModeBase_NoRegister();
	TESTUNREALENGINE_API UClass* Z_Construct_UClass_ATestUnrealEngineGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_TestUnrealEngine();
// End Cross Module References
	void ATestUnrealEngineGameModeBase::StaticRegisterNativesATestUnrealEngineGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ATestUnrealEngineGameModeBase_NoRegister()
	{
		return ATestUnrealEngineGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ATestUnrealEngineGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATestUnrealEngineGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_TestUnrealEngine,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATestUnrealEngineGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "TestUnrealEngineGameModeBase.h" },
		{ "ModuleRelativePath", "TestUnrealEngineGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATestUnrealEngineGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATestUnrealEngineGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATestUnrealEngineGameModeBase_Statics::ClassParams = {
		&ATestUnrealEngineGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ATestUnrealEngineGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATestUnrealEngineGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATestUnrealEngineGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATestUnrealEngineGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATestUnrealEngineGameModeBase, 2810097898);
	template<> TESTUNREALENGINE_API UClass* StaticClass<ATestUnrealEngineGameModeBase>()
	{
		return ATestUnrealEngineGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATestUnrealEngineGameModeBase(Z_Construct_UClass_ATestUnrealEngineGameModeBase, &ATestUnrealEngineGameModeBase::StaticClass, TEXT("/Script/TestUnrealEngine"), TEXT("ATestUnrealEngineGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATestUnrealEngineGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
