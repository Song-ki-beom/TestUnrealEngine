// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"
#include "MyCharacter.h"

UMyAnimInstance::UMyAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("AnimMontage'/Game/Animations/Yin_Skeleton_Montage.Yin_Skeleton_Montage'"));
	if(AM.Succeeded())
		AttackMontage = AM.Object;
}

void UMyAnimInstance::PlayAttackMontage() // NativeUpdateAnimation()흠 뭐가 문제지
{
		Montage_Play(AttackMontage,1.f);
	
}

void UMyAnimInstance::JumpToSection(int32 SectionIndex)
{
	FName Name = GetAttackMontageName(SectionIndex);
	Montage_JumpToSection(Name, AttackMontage);
}

FName UMyAnimInstance::GetAttackMontageName(int32 SectionIndex)
{

	return FName(*FString::Printf(TEXT("Attack%d"),SectionIndex));
}

void UMyAnimInstance::AnimNotify_AttackHit()
{

	//UE_LOG(LogTemp, Log, TEXT("AnimNotify_AttackHit"));
	OnAttackHit.Broadcast();
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds) //���� ��������� ���� ���������� ȣ��Ǵ� �Լ�, �� �����Ӹ��� ȣ��
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size(); // �ӵ� ������ 
		
		auto Character = Cast<AMyCharacter>(Pawn);
		Vertical = Character->UpDownValue;
		Horizontal = Character->LeftRightValue;
		if (Character) {
			IsFalling = Character->GetMovementComponent()->IsFalling();
		}
	}

}


