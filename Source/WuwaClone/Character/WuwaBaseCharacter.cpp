// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WuwaBaseCharacter.h"


AWuwaBaseCharacter::AWuwaBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AWuwaBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWuwaBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWuwaBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

