// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "MyAnimInstance.h"
// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("SkeletalMesh'/Game/ParagonYin/Characters/Heroes/Yin/Meshes/Yin.Yin'"));
	if (SM.Succeeded()) {
		GetMesh()->SetSkeletalMesh(SM.Object); // Character.h의 Mesh 가 private 이므로 Mesh 를 가져오는 GetMesh() 를 사용하여 가져온다.
	}

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	SpringArm->SetupAttachment(GetCapsuleComponent()); // SetupAttachment 로 스프링암(셀프카메라봉) 을 누구(부모)에 항상 붙일지 정하는것 , 
	//ACharacter.h 의 생성자를 참고하면 CapsuleComponent를 RootComponent에 지정하였으므로 얘로 지정
	Camera->SetupAttachment(SpringArm); // 셀카봉(SpringArm) 끝에 카메라 붙힘 
	
	SpringArm->TargetArmLength = 500.f;
	SpringArm->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f));
	GetMesh()->SetRelativeLocationAndRotation(
		FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));
	

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	auto AnimInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AMyCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AMyCharacter::Attack);
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyCharacter::UpDown); //축(axis)랑 함수랑 binding 
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Yaw"), this, &AMyCharacter::Yaw);

}

void AMyCharacter::UpDown(float Value) 
{
	if (Value == 0.f)
		return;
	AddMovementInput(GetActorForwardVector(), Value);
	//UE_LOG(LogTemp, Warning, TEXT("UpDown %f"), Value);

}

void AMyCharacter::LeftRight(float Value)
{
	if (Value == 0.f)
		return;
	AddMovementInput(GetActorRightVector(), Value);

	//UE_LOG(LogTemp, Warning, TEXT("LeftRight %f"), Value);
}

void AMyCharacter::Yaw(float Value) {
	AddControllerYawInput(Value);
}

void AMyCharacter::Attack() // jump나 attack 같이 어떤 상호작용에서만 작동하는 애니매이션은 animinstance에서 변수를 조절하는 것이 아닌
// 여기서 전환 변수를 관리한다.
{ //애니메이션 관련된건, 스켈레톤이 부착된 mesh 에서 가져올수 있음 
	if (IsAttacking)
		return;
	auto AnimInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
	if (AnimInstance)
	{
		AnimInstance->PlayAttackMontage();
	}
	IsAttacking = true;
}
