// Fill out your copyright notice in the Description page of Project Settings.


#include "MyWeapon.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "MyAnimInstance.h"
#include "CollisionQueryParams.h"

// Sets default values
AMyWeapon::AMyWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	

	

		Weapon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WEAPON"));
		static ConstructorHelpers::FObjectFinder<UStaticMesh> SW(TEXT("StaticMesh'/Game/ParagonYin/FX/Meshes/Splines/SM_Forward_Burst_Splines.SM_Forward_Burst_Splines'"));
		if (SW.Succeeded()) {
			Weapon->SetStaticMesh(SW.Object);
		}
		Weapon->SetCollisionProfileName(TEXT("NoCollision"));
	
	

}

// Called when the game starts or when spawned
void AMyWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

