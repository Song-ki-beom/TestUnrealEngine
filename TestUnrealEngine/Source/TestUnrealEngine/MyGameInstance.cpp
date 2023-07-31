// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
UMyGameInstance::UMyGameInstance() {

	static ConstructorHelpers::FObjectFinder<UDataTable> DATA(TEXT("DataTable'/Game/Data/StatTable.StatTable'"));
	                                                 
	if (DATA.Succeeded())
	{
		UE_LOG(LogTemp, Error, TEXT("Load data table Succeeded"));
		MyStats = DATA.Object;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to find data table"));
	}


}
FMyCharacterData* UMyGameInstance::GetStatData(int32 Level)
{
	if (MyStats != nullptr) {
		FMyCharacterData* CharacterData = MyStats->FindRow<FMyCharacterData>(*FString::FromInt(Level), TEXT(""));
		//find by level

		if (CharacterData != nullptr) {
			return CharacterData;
		}

	}
	return nullptr;
}

void UMyGameInstance::Init() {
	Super::Init();
	UE_LOG(LogTemp, Warning, TEXT("MyGameInstance %d"), GetStatData(1)->Attack);


}



