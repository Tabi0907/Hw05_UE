// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HW05_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// [가이드 2] 이동 및 회전 함수 선언
	void Move();
	void Turn();

	// [가이드 2] 랜덤 반복 실행 (10회) 함수 선언
	void ExecuteRandomMovement();
};
