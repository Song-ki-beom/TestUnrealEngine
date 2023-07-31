// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyCharacterWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTUNREALENGINE_API UMyCharacterWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void BindHp(class UMyStatComponent* StatComp);
	void UpdateHp();

private:
	TWeakObjectPtr<class UMyStatComponent> CurrentStatComp;
	UPROPERTY(meta=(BindWidget)) // bind mapping this variable with BP widget's ui..should be same name 
	class UProgressBar* PB_HpBar;


	
};
