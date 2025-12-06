// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Enemy_Interface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemy_Interface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AURA_API IEnemy_Interface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	// Functions to highlight and unhighlight enemy actors
	virtual void HighlightActor() = 0;
	virtual void UnHighlightActor() = 0;
};
