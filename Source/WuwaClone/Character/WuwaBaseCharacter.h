// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WuwaBaseCharacter.generated.h"

class UMaterialInterface;
class USkeletalMeshComponent;

UCLASS(Abstract)
class WUWACLONE_API AWuwaBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AWuwaBaseCharacter();
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	virtual void BeginPlay() override;

private:
	void UpdateOutlineMesh();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Appearance|Outline", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> OutlineMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Appearance|Outline", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMaterialInterface> OutlineMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Appearance|Outline", meta = (AllowPrivateAccess = "true"))
	bool bEnableOutline = true;

};
