// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyCharacter.h"
AMyGameModeBase::AMyGameModeBase() {
	DefaultPawnClass = AMyCharacter::StaticClass(); //AmyPawn 의 스태틱 객체를 함수 반환값으로 받아온다.

	static ConstructorHelpers::FClassFinder<ACharacter> BP_Char(TEXT("Blueprint'/Game/Blueprint/BP_MyCharacter.BP_MyCharacter_C'")); // 클래스 위치 복붙 후
	//복붙 후 꼭 문자열 끝에 _C를 넣어야함 

	if (BP_Char.Succeeded())
	{
		DefaultPawnClass = BP_Char.Class;
	}
}