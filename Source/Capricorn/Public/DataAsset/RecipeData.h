// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RecipeData.generated.h"
#define LOCTEXT_NAMESPACE "Item"
/**
 * 
 */

class AIngredients;

USTRUCT(BlueprintType)
struct FRecipeIngredient
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
	AIngredients* Ingredients;
	UPROPERTY(BlueprintReadWrite)
	int32 Num;
	
};

UCLASS(BlueprintType)
class CAPRICORN_API URecipeData : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	FText RecipeName = LOCTEXT("Item_SimpleStirFriedBokChoy","清炒白菜");
	UPROPERTY(EditAnywhere)
	FRecipeIngredient RecipeIngredient;
	
};
