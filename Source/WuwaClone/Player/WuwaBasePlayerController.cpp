// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/WuwaBasePlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"
#include "Math/RotationMatrix.h"
#include "WuwaClone.h"

AWuwaBasePlayerController::AWuwaBasePlayerController()
{
}

void AWuwaBasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// 입력 매핑은 로컬 플레이어에만 등록한다. 서버에는 LocalPlayer가 없다.
	if (IsLocalPlayerController() == false)
	{
		return;
	}

#if !UE_BUILD_SHIPPING
	ValidateAssignedAssets();
#endif

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if (IsValid(EnhancedInputComponent) == false)
	{
		UE_LOG(LogWuwa, Error, TEXT("Enhanced InputComponent가 필요합니다: %s"), *GetNameSafe(this));
		return;
	}

	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (IsValid(InputSubsystem) == false)
	{
		UE_LOG(LogWuwa, Error, TEXT("로컬 입력 Subsystem을 찾을 수 없습니다: %s"), *GetNameSafe(this));
		return;
	}

	InputSubsystem->AddMappingContext(DefaultMappingContext, 0);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AWuwaBasePlayerController::Move);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AWuwaBasePlayerController::Jump);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AWuwaBasePlayerController::Look);
}

void AWuwaBasePlayerController::Move(const FInputActionValue& Value)
{
	ACharacter* ControlledCharacter = GetCharacter();
	if (IsValid(ControlledCharacter) == false)
	{
		return;
	}

	const FVector2D MovementInput = Value.Get<FVector2D>();
	const FRotator YawRotation(0.0f, GetControlRotation().Yaw, 0.0f);
	const FRotationMatrix RotationMatrix(YawRotation);

	ControlledCharacter->AddMovementInput(RotationMatrix.GetUnitAxis(EAxis::X), MovementInput.Y);
	ControlledCharacter->AddMovementInput(RotationMatrix.GetUnitAxis(EAxis::Y), MovementInput.X);
}

void AWuwaBasePlayerController::Jump()
{
	ACharacter* ControlledCharacter = GetCharacter();
	if (IsValid(ControlledCharacter) == true)
	{
		ControlledCharacter->Jump();
	}
}

void AWuwaBasePlayerController::Look(const FInputActionValue& Value)
{
	const FVector2D LookInput = Value.Get<FVector2D>();
	AddYawInput(LookInput.X);
	AddPitchInput(LookInput.Y);
}

#if !UE_BUILD_SHIPPING
void AWuwaBasePlayerController::ValidateAssignedAssets() const
{
	checkf(IsValid(DefaultMappingContext) == true, TEXT("DefaultMappingContext를 지정해야 합니다: %s"), *GetNameSafe(this));
	checkf(IsValid(MoveAction) == true, TEXT("MoveAction을 지정해야 합니다: %s"), *GetNameSafe(this));
	checkf(IsValid(JumpAction) == true, TEXT("JumpAction을 지정해야 합니다: %s"), *GetNameSafe(this));
	checkf(IsValid(LookAction) == true, TEXT("LookAction을 지정해야 합니다: %s"), *GetNameSafe(this));
	checkf(MoveAction->ValueType == EInputActionValueType::Axis2D, TEXT("MoveAction은 Axis2D 타입이어야 합니다: %s"), *GetNameSafe(this));
	checkf(JumpAction->ValueType == EInputActionValueType::Boolean, TEXT("JumpAction은 Digital (bool) 타입이어야 합니다: %s"), *GetNameSafe(this));
	checkf(LookAction->ValueType == EInputActionValueType::Axis2D, TEXT("LookAction은 Axis2D 타입이어야 합니다: %s"), *GetNameSafe(this));
}
#endif
