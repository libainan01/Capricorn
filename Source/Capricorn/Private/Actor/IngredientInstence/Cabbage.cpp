// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/IngredientInstence/Cabbage.h"

ACabbage::ACabbage()
{
}

EInteractionType ACabbage::Interact(AActor* Interactor,EInteractionType InteractionType)
{
	Super::Interact(Interactor,InteractionType);

	return EInteractionType::None;
}
