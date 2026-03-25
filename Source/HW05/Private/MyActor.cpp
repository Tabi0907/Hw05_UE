#include "MyActor.h"
// [필수!] GEngine을 통해 화면에 로그를 띄우기 위해 반드시 추가해야 합니다.
#include "Engine/Engine.h" 

AMyActor::AMyActor()
{
    // 매 프레임마다 실행되는 Tick 기능은 이번 실습에서 필요 없으므로 꺼둡니다.
    PrimaryActorTick.bCanEverTick = false;
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    // 시작하자마자 10회 랜덤 이동/회전 로직을 실행합니다.
    ExecuteRandomMovement();
}

void AMyActor::ExecuteRandomMovement()
{
    // [가이드 2] 총 10회 반복 실행
    for (int32 i = 0; i < 10; ++i)
    {
        // 무작위 이동과 회전 함수 호출
        Move();
        Turn();
    }
}

void AMyActor::Move()
{
    // 1. 현재 좌표 가져오기
    FVector CurrentLocation = GetActorLocation();

    // 2. 랜덤한 이동 거리 설정 (예: X, Y축으로 -100 ~ 100 사이)
    float RandomDistanceX = FMath::RandRange(-100.0f, 100.0f);
    float RandomDistanceY = FMath::RandRange(-100.0f, 100.0f);

    // 3. 현재 좌표에서 설정 거리만큼 더하여 새로운 좌표 계산 및 적용
    FVector NewLocation = CurrentLocation + FVector(RandomDistanceX, RandomDistanceY, 0.0f);
    SetActorLocation(NewLocation);

    // [가이드 3] 실시간 정보 로그 출력
    // 게임 실행 화면에 출력 (AddOnScreenDebugMessage)
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Move to : %s"), *NewLocation.ToString()));
    }

    // 콘솔창(출력 로그)에 출력 (UE_LOG)
    UE_LOG(LogTemp, Warning, TEXT("Move to : %s"), *NewLocation.ToString());
}

void AMyActor::Turn()
{
    // 1. 현재 회전값 가져오기
    FRotator CurrentRotation = GetActorRotation();

    // 2. 랜덤한 회전 각도 설정 (예: Z축(Yaw) 기준 0 ~ 180도)
    float RandomYaw = FMath::RandRange(0.0f, 180.0f);

    // 3. 현재 각도에서 설정 각도만큼 더하여 새로운 회전 적용
    FRotator NewRotation = CurrentRotation + FRotator(0.0f, RandomYaw, 0.0f);
    SetActorRotation(NewRotation);
}