// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Blueprint/Data/InteractionTypes.h"
#include "Interactable.generated.h"
/**
 *交互接口，需要配合交互组件一起使用
 */

// This class does not need to be modified.
UINTERFACE(MinimalAPI,Blueprintable)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CAPRICORN_API IInteractable
{
	GENERATED_BODY()
public:
	//执行指定的交互
	virtual EInteractionType Interact(AActor* Interactor,EInteractionType InteractionType) = 0;
	//返回当前对象对指定交互者可用的交互选项列表
	virtual TArray<EInteractionType> GetAvailableInteractions(AActor* Interactor) =0;
	
};
