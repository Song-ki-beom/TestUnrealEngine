// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPawn.h"
AMyGameModeBase::AMyGameModeBase() {
	DefaultPawnClass = AMyPawn::StaticClass(); //AmyPawn �� ����ƽ ��ü�� �Լ� ��ȯ������ �޾ƿ´�.
}