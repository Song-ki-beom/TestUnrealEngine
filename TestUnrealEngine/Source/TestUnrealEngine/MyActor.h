// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS() // REFLECTION : ��Ŭ�������� �����ϴ� Ŭ�������� ���� (������Ÿ��)
class TESTUNREALENGINE_API AMyActor : public AActor //AA ->A��� CONVENTION(���̹� ����) �ʿ�
{
	GENERATED_BODY() //REFLECTION : �����Ϸ����� �����ϴ� �ּ� OR ��Ÿ������
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = BattleStat)
		int32 Hp;
	UPROPERTY(EditAnywhere, Category = BattleStat)
		int32 Mp;
	UPROPERTY(EditAnywhere, Category = BattleStat)
		float RotateSpeed = 30.f;
};