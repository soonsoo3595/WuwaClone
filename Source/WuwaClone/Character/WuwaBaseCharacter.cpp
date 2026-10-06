// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WuwaBaseCharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Materials/MaterialInterface.h"


AWuwaBaseCharacter::AWuwaBaseCharacter()
{
	OutlineMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("OutlineMesh"));
	OutlineMesh->SetupAttachment(GetMesh());
	OutlineMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	OutlineMesh->SetGenerateOverlapEvents(false);
	OutlineMesh->SetCastShadow(false);
	OutlineMesh->SetIsReplicated(false);
	OutlineMesh->PrimaryComponentTick.bAllowTickOnDedicatedServer = false;
	OutlineMesh->SetComponentTickEnabled(false);
	OutlineMesh->SetBoundsScale(1.02f);

	// Controller 회전과 몸체 회전을 분리하고 이동 방향으로 몸체를 회전한다.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	// 버튼 유지 시간에 영향을 받지 않는 단발 점프.
	JumpMaxHoldTime = 0.0f;
}

void AWuwaBaseCharacter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	UpdateOutlineMesh();
}

void AWuwaBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	UpdateOutlineMesh();
}

void AWuwaBaseCharacter::UpdateOutlineMesh()
{
	const bool bShouldRenderOutline = bEnableOutline && OutlineMaterial
		&& GetMesh()->GetSkeletalMeshAsset() && GetNetMode() != NM_DedicatedServer;

	// 본체의 뼈 포즈를 공유하고 외곽선용 애니메이션은 별도로 갱신하지 않는다.
	OutlineMesh->SetLeaderPoseComponent(bShouldRenderOutline ? GetMesh() : nullptr, true, false);
	OutlineMesh->SetSkeletalMeshAsset(bShouldRenderOutline ? GetMesh()->GetSkeletalMeshAsset() : nullptr);
	OutlineMesh->EmptyOverrideMaterials();
	if (bShouldRenderOutline)
	{
		for (int32 MaterialIndex = 0; MaterialIndex < OutlineMesh->GetNumMaterials(); ++MaterialIndex)
		{
			OutlineMesh->SetMaterial(MaterialIndex, OutlineMaterial);
		}
	}
	OutlineMesh->SetVisibility(bShouldRenderOutline);
	OutlineMesh->SetComponentTickEnabled(false);
}
