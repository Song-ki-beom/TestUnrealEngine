// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "MyAnimInstance.h"
#include "CollisionQueryParams.h"
#include "DrawDebugHelpers.h"
#include "MyWeapon.h"
#include "MyStatComponent.h"
#include "Components/WidgetComponent.h"
#include "MyCharacterWidget.h"
// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("SkeletalMesh'/Game/ParagonYin/Characters/Heroes/Yin/Meshes/Yin.Yin'"));
	if (SM.Succeeded()) {
		GetMesh()->SetSkeletalMesh(SM.Object); // Character.h�� Mesh �� private �̹Ƿ� Mesh �� �������� GetMesh() �� ����Ͽ� �����´�.
	}

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	SpringArm->SetupAttachment(GetCapsuleComponent()); // SetupAttachment �� ��������(����ī�޶��) �� ����(�θ�)�� �׻� ������ ���ϴ°� , 
	//ACharacter.h �� �����ڸ� �����ϸ� CapsuleComponent�� RootComponent�� �����Ͽ����Ƿ� ��� ����
	Camera->SetupAttachment(SpringArm); // ��ī��(SpringArm) ���� ī�޶� ���� 
	
	SpringArm->TargetArmLength = 500.f;
	SpringArm->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f));
	GetMesh()->SetRelativeLocationAndRotation(
		FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));

	Stat = CreateDefaultSubobject<UMyStatComponent>(TEXT("STAT"));
	HpBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("HPBAR"));
	HpBar->SetupAttachment(GetMesh());
	HpBar->SetWidgetSpace(EWidgetSpace::Screen); // ui type showing on "Screen" that means never disappear from Screen
	HpBar->SetRelativeLocation(FVector(0.f, 0.f, 200.f));
	static ConstructorHelpers::FClassFinder<UUserWidget> UW(TEXT("WidgetBlueprint'/Game/UI/WBP_HpBar.WBP_HpBar_C'"));

	if (UW.Succeeded()) {
		HpBar->SetWidgetClass(UW.Class);
		HpBar->SetDrawSize(FVector2D(200.f, 50.f));
	}
	
	
	
	
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	FName WeaponSocket(TEXT("hand_l_socket"));

	auto CurrentWeapon = GetWorld()->SpawnActor<AMyWeapon>(FVector::ZeroVector, FRotator::ZeroRotator);
	if (CurrentWeapon) {
		CurrentWeapon->AttachToComponent(GetMesh(),
			FAttachmentTransformRules::SnapToTargetNotIncludingScale,
			WeaponSocket
		);
	}
}

void AMyCharacter::PostInitializeComponents()
{
	
		Super::PostInitializeComponents();

		AnimInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
		if (AnimInstance) {
			AnimInstance->OnMontageEnded.AddDynamic(this, &AMyCharacter::OnAttackMontageEnded);
			AnimInstance->OnAttackHit.AddUObject(this, &AMyCharacter::AttackCheck);


		}

		HpBar->InitWidget();

		auto HpWidget = Cast<UMyCharacterWidget>(HpBar->GetUserWidgetObject());
		if (HpWidget)
			HpWidget->BindHp(Stat);
	
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
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyCharacter::UpDown); //��(axis)�� �Լ��� binding 
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Yaw"), this, &AMyCharacter::Yaw);

}

float AMyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Stat->OnAttacked(DamageAmount);
	return 0.0f;
}

void AMyCharacter::UpDown(float Value) 
{
	
	UpDownValue = Value;
	AddMovementInput(GetActorForwardVector(), Value);
	//UE_LOG(LogTemp, Warning, TEXT("UpDown %f"), Value);

}

void AMyCharacter::LeftRight(float Value)
{
	if (Value == 0.f)
		return;
	LeftRightValue = Value;
	AddMovementInput(GetActorRightVector(), Value);

	//UE_LOG(LogTemp, Warning, TEXT("LeftRight %f"), Value);
}

void AMyCharacter::Yaw(float Value) {
	AddControllerYawInput(Value);
}

void AMyCharacter::Attack() 
{ 
	if (IsAttacking)
		return;
	
		AnimInstance->PlayAttackMontage();
		AnimInstance->JumpToSection(AttackIndex);
		AttackIndex = (AttackIndex + 1) % 3;
	IsAttacking = true;
}

void AMyCharacter::AttackCheck()
{
	FHitResult HitResult;
	FCollisionQueryParams Params(NAME_None, false, this);
	float AttackRange = 100.f;
	float AttackRadius = 50.f;

	bool bResult = GetWorld()->SweepSingleByChannel(
		HitResult,
		GetActorLocation(),
		GetActorLocation() + GetActorForwardVector() * AttackRange,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(AttackRadius),
		Params);


	FVector Vec = GetActorForwardVector() * AttackRange;
	FVector Center = GetActorLocation() + Vec * 0.5f;
	float HalfHeight = AttackRange * 0.5f + AttackRadius;
	FQuat Rotation = FRotationMatrix::MakeFromZ(Vec).ToQuat();
	FColor DrawColor;
	if (bResult)
		DrawColor = FColor::Green;
	else
		DrawColor = FColor::Red;


	DrawDebugCapsule(GetWorld(), Center, HalfHeight, AttackRadius,
		Rotation, DrawColor, false, 2.f);

	if (bResult && HitResult.Actor.IsValid()) {
		UE_LOG(LogTemp, Log, TEXT("Hit Actor : %s"), *HitResult.Actor->GetName());
		
		FDamageEvent DamageEvent;
		HitResult.Actor->TakeDamage(Stat->GetAttack(), DamageEvent, GetController(), this);

	}



	
	
}

void AMyCharacter::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	IsAttacking = false;
}
