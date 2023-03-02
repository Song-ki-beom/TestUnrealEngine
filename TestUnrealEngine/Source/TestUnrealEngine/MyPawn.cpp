// Fill out your copyright notice in the Description page of Project Settings.
//게임 프레임워크 : 게임의 틀을 이루는 게임 규칙 , 플레이어 입력과 컨트롤, 카메라, 유저 , 인터페이스 등의 코어 시스템을 말한다.

#include "MyPawn.h"
#include "GameFrameWork/FloatingPawnMovement.h"
// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("MESH"));
	Movement = CreateDefaultSubobject <UFloatingPawnMovement>(TEXT("MOVEMENT"));

	RootComponent = Mesh;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Lamp_Ceiling.SM_Lamp_Ceiling'"));
	if (SM.Succeeded()) {
		Mesh->SetStaticMesh(SM.Object);
	}

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyPawn::UpDown); //축(axis)랑 함수랑 binding 
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyPawn::LeftRight);
}

void AMyPawn::UpDown(float Value)
{
	if (Value == 0.f)
		return;
	AddMovementInput(GetActorForwardVector(), Value);
	//UE_LOG(LogTemp, Warning, TEXT("UpDown %f"), Value);

}

void AMyPawn::LeftRight(float Value)
{
	if (Value == 0.f)
		return;
	AddMovementInput(GetActorRightVector(), Value);

	//UE_LOG(LogTemp, Warning, TEXT("LeftRight %f"), Value);
}

