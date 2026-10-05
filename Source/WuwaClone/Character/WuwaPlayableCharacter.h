// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/WuwaBaseCharacter.h"
#include "WuwaPlayableCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

/** 플레이어가 조종하는 캐릭터 기반. 입력 바인딩은 PlayerController에서 담당한다. */
UCLASS(Abstract)
class WUWACLONE_API AWuwaPlayableCharacter : public AWuwaBaseCharacter
{
	GENERATED_BODY()

public:
	AWuwaPlayableCharacter();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FollowCamera;
};
