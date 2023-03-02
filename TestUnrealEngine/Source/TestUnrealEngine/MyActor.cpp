// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject < UStaticMeshComponent>(TEXT("MESH")); //CreateDefaultSubobject->����Ʈ������ ���� ����(�ڿ����� ���� x) ..TEXT�� L_MESH�� Ȯ��Ǵ� ���ڿ� ȯ�� ��ġ, ���� ������ ���� ȣȯ�Ͽ� ����(ũ�ν� �÷���)
	RootComponent = Mesh; //transform �� �����ϴ� ������Ʈ�� ��� RootComponent �� �����ؾ��Ѵ�.
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Lamp_Ceiling.SM_Lamp_Ceiling'")); //�޽��� �ε��ϱ� ���� ���δ� sm ���� �� ����
	if (SM.Succeeded()) {
		Mesh->SetStaticMesh(SM.Object);
	}
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay() //�����Ҷ�
{
	Super::BeginPlay();

	//ī�װ�, �α� ����(Verbosity) , ����, ���ڸ� �ʿ�� �ϴ� �α� ��ũ�� 
	UE_LOG(LogTemp,Warning, TEXT("BeginPlay %d"),3)
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime) // �� �����Ӹ��� ����
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Error, TEXT("Tick %f"), DeltaTime);
	AddActorLocalRotation(FRotator(0.f,RotateSpeed*DeltaTime,0.f));  //pitch(y��) , roll(x��), Yaw(z��) / FRotator(y,z,x)

}

