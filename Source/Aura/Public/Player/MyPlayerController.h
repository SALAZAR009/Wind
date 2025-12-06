// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemy_Interface;


UCLASS()
class AURA_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMyPlayerController();
	virtual void PlayerTick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:

	UPROPERTY(EditAnywhere, Category="Inputs")
	TObjectPtr <UInputMappingContext> PlayerMappingContext;

	UPROPERTY(EditAnywhere, Category = "Inputs")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const struct FInputActionValue& InputActionvalue);

	void CursorTrace();

	TScriptInterface<IEnemy_Interface> ThisActor;
	TScriptInterface<IEnemy_Interface> NextActor;

};
