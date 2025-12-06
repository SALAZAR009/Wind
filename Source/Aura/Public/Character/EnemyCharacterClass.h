// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/WindBaseCharacterClass.h"
#include "Interactions/Enemy_Interface.h"
#include "EnemyCharacterClass.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AEnemyCharacterClass : public AWindBaseCharacterClass , public IEnemy_Interface
{
	GENERATED_BODY()

public:

	AEnemyCharacterClass();

	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	
	
};
