// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS() // REFLECTION : 유클래스에서 제공하는 클래스임을 각인 (데이터타입)
class TESTUNREALENGINE_API AMyActor : public AActor //AA ->A라는 CONVENTION(네이밍 센스) 필요
{
	GENERATED_BODY() //REFLECTION : 컴파일러에서 참고하는 주석 OR 메타데이터
	
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
