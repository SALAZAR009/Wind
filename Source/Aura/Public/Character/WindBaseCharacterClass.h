// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WindBaseCharacterClass.generated.h"

UCLASS(Abstract)
class AURA_API AWindBaseCharacterClass : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWindBaseCharacterClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "CombatWeapon")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;


};
