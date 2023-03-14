// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyCharacter.h"
AMyGameModeBase::AMyGameModeBase() {
	DefaultPawnClass = AMyCharacter::StaticClass(); //AmyPawn �� ����ƽ ��ü�� �Լ� ��ȯ������ �޾ƿ´�.

	static ConstructorHelpers::FClassFinder<ACharacter> BP_Char(TEXT("Blueprint'/Game/Blueprint/BP_MyCharacter.BP_MyCharacter_C'")); // Ŭ���� ��ġ ���� ��
	//���� �� �� ���ڿ� ���� _C�� �־���� 

	if (BP_Char.Succeeded())
	{
		DefaultPawnClass = BP_Char.Class;
	}
}