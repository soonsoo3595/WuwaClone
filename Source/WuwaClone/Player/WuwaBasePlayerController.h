// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WuwaBasePlayerController.generated.h"

class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

UCLASS(Abstract)
class WUWACLONE_API AWuwaBasePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AWuwaBasePlayerController();

protected:
	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

private:
	void Move(const FInputActionValue& Value);
	void Jump();
	void Look(const FInputActionValue& Value);

#if !UE_BUILD_SHIPPING
	void ValidateAssignedAssets() const;
#endif
};
