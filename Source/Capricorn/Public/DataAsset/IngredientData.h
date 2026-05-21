// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#define LOCTEXT_NAMESPACE "Item"

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "IngredientData.generated.h"


UENUM(BlueprintType)
enum class EIngredientState :uint8
{
	//原料
	Raw,
	//切碎
	Chopped,
	//研磨
	Ground,
	//煮熟
	Cooked,
	//炒熟
	Fried,
	//焦糊
	Burned,
};

USTRUCT(BlueprintType)
struct FIngredientState
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TArray<EIngredientState> IngredientStates;
};
/**
 * 
 */
UCLASS(BlueprintType)
class CAPRICORN_API UIngredientData : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "物品属性|索引")
	FName Id = "cabbage";
	UPROPERTY(EditAnywhere,Category = "物品属性|提示文本")
	FText DisplayName = LOCTEXT("Item_Cabbage","白菜");
	UPROPERTY(EditAnywhere)
	TMap<EIngredientState,UStaticMesh*> StateMeshes;
	UPROPERTY(EditAnywhere)
	TMap<EIngredientState,FIngredientState> Transitions;
	
};
#undef LOCTEXT_NAMESPACE