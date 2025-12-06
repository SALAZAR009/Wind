// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/EnemyCharacterClass.h"
#include "Aura/Aura.h"

AEnemyCharacterClass::AEnemyCharacterClass()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void AEnemyCharacterClass::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(Default_CustomDepthStencilValue);
	WeaponMesh->SetRenderCustomDepth(true);
	WeaponMesh->SetCustomDepthStencilValue(Default_CustomDepthStencilValue);
}

void AEnemyCharacterClass::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	WeaponMesh->SetRenderCustomDepth(false);
}
