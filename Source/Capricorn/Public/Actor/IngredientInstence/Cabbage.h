// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/Ingredients.h"
#include "Cabbage.generated.h"

/**
 * 切菜板
 */
UCLASS()
class CAPRICORN_API ACabbage : public AIngredients
{
	GENERATED_BODY()
	ACabbage();
public:
	
	virtual EInteractionType Interact(AActor* Interactor,EInteractionType InteractionType) override;
	
};
