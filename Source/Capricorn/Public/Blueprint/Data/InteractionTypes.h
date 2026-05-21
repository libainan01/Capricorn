// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionTypes.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EInteractionType:uint8
{
	None,
	PickUp,     // 拾起
	PutDown,    // 放下
	Process,    // 操作（切菜/烹饪）
	Talk,       // 交流
	Inspect,    // 查看
};

USTRUCT(BlueprintType)
struct FInteractionOption
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	EInteractionType Type = EInteractionType::None;

	UPROPERTY(BlueprintReadOnly)
	FText HintText;

	UPROPERTY(BlueprintReadOnly)
	int32 Priority = 0;
};
