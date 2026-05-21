// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"

/**
 * 交互组件，用作交互行为判断
 */
class UUItemHolderComponent;
class USphereComponent;
enum class EInteractionType : uint8;

//目标变化时广播
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetChanged,AActor*,NewTarget);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAvailableInteractionsChanged,const TArray<FInteractionOption>&, Options);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CAPRICORN_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractionComponent();

	//交互范围半径
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "交互")
	float InteractionRadius = 150.f;

	//方向权重
	UPROPERTY(EditAnywhere,Category = "交互")
	float DirectionWeight = 0.6f;

	//当前目标
	UPROPERTY(BlueprintReadOnly,Category = "交互")
	AActor* CurrentTarget = nullptr;

	// 当前目标的可用交互列表
	UPROPERTY(BlueprintReadOnly,Category = "交互")
	TArray<FInteractionOption> CurrentOptions;

	// 委托
	UPROPERTY(BlueprintAssignable)
	FOnTargetChanged OnTargetChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAvailableInteractionsChanged OnAvailableInteractionsChanged;
	
	//当前目标可用的交互列表
	UPROPERTY()
	UUItemHolderComponent* HolderSlot;
	UPROPERTY()
	TArray<AActor*> InteractiveObjects;
	UFUNCTION()
	void TryInteract(EInteractionType interactiontype,AActor* Interactor);
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
};
