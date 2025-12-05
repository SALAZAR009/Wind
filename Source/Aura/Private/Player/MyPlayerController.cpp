// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MyPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"


AMyPlayerController::AMyPlayerController()
{
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//Check Player Mapping Context
	check(PlayerMappingContext);


	//Add Input Mapping Context
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(PlayerMappingContext, 0);

	//Set Show mouse cursor
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	//Set mouse which help me to access through keyboard and UI as well
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//Check Input Component
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent> (InputComponent);

	//Bind Move Action
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyPlayerController::Move);

}

void AMyPlayerController::Move(const FInputActionValue& InputActionvalue)
{
	//Get input axis value
	const FVector2D InputAxisVector = InputActionvalue.Get<FVector2D>();
	//Get control rotation
	const FRotator Rotation = GetControlRotation();
	//Get yaw rotation
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	//Get forward vector
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	//Get right vector
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	//Add movement
	if (APawn* ControlledPawn = GetPawn())
	{
		//Add movement in forward direction
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		//Add movement in right direction
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
