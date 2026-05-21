// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAsset/IngredientData.h"
#include "GameFramework/Actor.h"
#include "Interface/Interactable.h"
#include "Ingredients.generated.h"

/**
 * 食材基类，记录了食材状态
 */

class USphereComponent;

UCLASS(BlueprintType)
class CAPRICORN_API AIngredients : public AActor , public IInteractable
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "基础属性")
	UIngredientData* IngredientData;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "基础属性")
	EIngredientState CurrentState = EIngredientState::Raw;
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	UStaticMeshComponent* StaticMeshComponent;
	/// 尝试转变菜品当前的状态
	/// @param TargetIngredientState 需要变化的目标状态
	/// @return true是转化成功，false是转化失败
	UFUNCTION(BlueprintCallable)
	bool TryTransition(EIngredientState TargetIngredientState);

	//********************* IInteractable Begin**************************

	UPROPERTY(EditAnywhere)
	USphereComponent* InteractableCollision;
	virtual EInteractionType Interact(AActor* Interactor,EInteractionType InteractionType) override;

	UFUNCTION()
	virtual TArray<EInteractionType> GetAvailableInteractions(AActor* Interactor) override;

	UFUNCTION()
	void OnInteractionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent,AActor* OtherActor,UPrimitiveComponent* OtherComp,int32 OtherBodyIndex,bool bFormSweep,const FHitResult& SweepResult);

	UFUNCTION()
	void OnInteractionSphereEndOverlap(UPrimitiveComponent* OverlappedComponent,AActor* OtherActor,UPrimitiveComponent* OtherComp,int32 OtherBodyIndex);
	
	//********************* IInteractable End***************************
	// Sets default values for this actor's properties
	AIngredients();

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	/// 根据当前的状态更新食物的网格体
	/// @param TargetIngredinetState 目标状态，用于索引静态网格体 
	/// @return 转化的目标网格体
	void UpdateStaticMesh (EIngredientState TargetIngredinetState);

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
