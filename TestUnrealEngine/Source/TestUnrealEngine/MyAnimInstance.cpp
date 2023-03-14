// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"


UMyAnimInstance::UMyAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("AnimMontage'/Game/Animations/Yin_Skeleton_Montage.Yin_Skeleton_Montage'"));
	if(AM.Succeeded())
		AttackMontage = AM.Object;
}

void UMyAnimInstance::PlayAttackMontage() // NativeUpdateAnimation()은 매 틱마다 실행되는 함수이므로,
// 특정 키를 눌렀을때만 발동되는 attack같은 경우는 애니메이션 처리도 클릭 당시에만 구현한다
{
	if (!Montage_IsPlaying(AttackMontage)) { // !Montage_IsPlaying 을 통해 이미 해당 애니메이션이 실행중이라면 재실행을 금한다.
		Montage_Play(AttackMontage,1.f);
	}
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds) //엔진 실행순서상 거의 최종적으로 호출되는 함수, 매 프레임마다 호출
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size(); // 속도 가져옴 
		
		auto Character = Cast<ACharacter>(Pawn);
		if (Character) {
			IsFalling = Character->GetMovementComponent()->IsFalling();
		}
	}

}


