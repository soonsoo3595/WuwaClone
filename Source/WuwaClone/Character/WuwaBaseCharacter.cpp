// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WuwaBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


AWuwaBaseCharacter::AWuwaBaseCharacter()
{
	// Controller 회전과 몸체 회전을 분리하고 이동 방향으로 몸체를 회전한다.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	// 버튼 유지 시간에 영향을 받지 않는 단발 점프.
	JumpMaxHoldTime = 0.0f;
}
