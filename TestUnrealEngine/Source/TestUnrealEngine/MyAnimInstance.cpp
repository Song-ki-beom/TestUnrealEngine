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

void UMyAnimInstance::PlayAttackMontage() // NativeUpdateAnimation()�� �� ƽ���� ����Ǵ� �Լ��̹Ƿ�,
// Ư�� Ű�� ���������� �ߵ��Ǵ� attack���� ���� �ִϸ��̼� ó���� Ŭ�� ��ÿ��� �����Ѵ�
{
	if (!Montage_IsPlaying(AttackMontage)) { // !Montage_IsPlaying �� ���� �̹� �ش� �ִϸ��̼��� �������̶�� ������� ���Ѵ�.
		Montage_Play(AttackMontage,1.f);
	}
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds) //���� ��������� ���� ���������� ȣ��Ǵ� �Լ�, �� �����Ӹ��� ȣ��
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size(); // �ӵ� ������ 
		
		auto Character = Cast<ACharacter>(Pawn);
		if (Character) {
			IsFalling = Character->GetMovementComponent()->IsFalling();
		}
	}

}


