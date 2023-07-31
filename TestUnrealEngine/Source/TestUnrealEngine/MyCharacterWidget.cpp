// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterWidget.h"
#include "MyStatComponent.h"
#include "Components/ProgressBar.h"
void UMyCharacterWidget::BindHp(class UMyStatComponent* StatComp) {
	//PB_HpBar1 = Cast<UProgressBar>(GetWidgetFromName(TEXT("PB_HpBar")))
	CurrentStatComp = StatComp;
	CurrentStatComp->OnHpChanged.AddUObject(this, &UMyCharacterWidget::UpdateHp);
};

void UMyCharacterWidget::UpdateHp()
{
	if(CurrentStatComp.IsValid())
	PB_HpBar->SetPercent(CurrentStatComp->GetHpRatio());
}
