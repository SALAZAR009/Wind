// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WindBaseCharacterClass.h"

// Sets default values
AWindBaseCharacterClass::AWindBaseCharacterClass()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = CreateDefaultSubobject <USkeletalMeshComponent> ("WeaponMesh");
	WeaponMesh->SetupAttachment(GetMesh(), FName("FWeaponHandSocket"));
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);


}

// Called when the game starts or when spawned
void AWindBaseCharacterClass::BeginPlay()
{
	Super::BeginPlay();
	
}



