// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAsset/IngredientData.h"
#include "GameFramework/Actor.h"
#include "Interface/Interactable.h"
#include "Kitchenware.generated.h"

class AIngredients;
class USphereComponent;
class UUItemHolderComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnProcessComplete);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractFailed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnIngredientAdded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnIngredientRemove);

UENUM(BlueprintType)
enum class EKitchenState : uint8
{
	Idle,
	Processing,
	Complete
};

UCLASS()
class CAPRICORN_API AKitchenware : public AActor , public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKitchenware();
	UPROPERTY(BlueprintReadOnly)
	TArray<AIngredients*> IngredientsSlot;
	
	UPROPERTY(BlueprintReadOnly)
	EKitchenState CurrentState = EKitchenState::Idle;
	
	UPROPERTY(BlueprintReadOnly)
	float Progress;
	
	UPROPERTY(BlueprintReadWrite)
	float CurrentProgress;
	
	UPROPERTY(EditAnywhere)
	USphereComponent* InteractableCollision;

	UPROPERTY()
	UUItemHolderComponent* ItemHolderComponent;
	
	//这里暂时不确定使用骨骼网格体还是静态网格体之后有可能做调整
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BoddyMesh;
	
	/// 尝试添加食材
	/// @param TargetIngredients 目标食材 
	/// @return 添加成功返回true，添加失败返回false
	UFUNCTION(BlueprintCallable)
	bool TryAddIngredient(AIngredients* TargetIngredients);
	

	UFUNCTION(BlueprintCallable)
	bool TryRemoveIngredient();

	//*************** Interaction Begin *******************
	virtual EInteractionType Interact(AActor* Interactor,EInteractionType InteractionType) override;

	virtual TArray<EInteractionType> GetAvailableInteractions(AActor* Interactor) override;
protected:
	UFUNCTION()
	void OnInteractableCollisionBeginOverlap (UPrimitiveComponent* OverlappedComponent,AActor* OtherActor,UPrimitiveComponent* OtherComp,int32 OtherBodyIndex,bool bFormSweep,const FHitResult& SweepResult);
	UFUNCTION()
	void OnInteractableCollisionEndOverlap(UPrimitiveComponent* OverlappedComponent,AActor* OtherActor,UPrimitiveComponent* OtherComp,int32 OtherBodyIndex);
	//*************** Interaction End **********************
	
	/// 允许添加的食材类型
	UPROPERTY(EditAnywhere)
	TArray<EIngredientState> AllowState;
	
	UFUNCTION()
	virtual bool CanAddIngredient();
	UFUNCTION()
	virtual bool OnProcessFinished();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
