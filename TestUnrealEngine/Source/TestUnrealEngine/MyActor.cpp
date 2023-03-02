// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject < UStaticMeshComponent>(TEXT("MESH")); //CreateDefaultSubobject->스마트포인터 형식 선언(자원관리 수동 x) ..TEXT는 L_MESH로 확장되는 문자열 환산 장치, 빌드 설정에 따라 호환하여 변경(크로스 플랫폼)
	RootComponent = Mesh; //transform 을 정의하는 컴포넌트는 모두 RootComponent 에 부착해야한다.
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Lamp_Ceiling.SM_Lamp_Ceiling'")); //메쉬를 로딩하기 위한 파인더 sm 선언 및 정의
	if (SM.Succeeded()) {
		Mesh->SetStaticMesh(SM.Object);
	}
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay() //시작할때
{
	Super::BeginPlay();

	//카테고리, 로깅 수준(Verbosity) , 형식, 인자를 필요로 하는 로깅 매크로 
	UE_LOG(LogTemp,Warning, TEXT("BeginPlay %d"),3)
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime) // 매 프레임마다 실행
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Error, TEXT("Tick %f"), DeltaTime);
	AddActorLocalRotation(FRotator(0.f,RotateSpeed*DeltaTime,0.f));  //pitch(y축) , roll(x축), Yaw(z축) / FRotator(y,z,x)

}

