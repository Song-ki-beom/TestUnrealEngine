// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPawn.h"
AMyGameModeBase::AMyGameModeBase() {
	DefaultPawnClass = AMyPawn::StaticClass(); //AmyPawn 의 스태틱 객체를 함수 반환값으로 받아온다.
}