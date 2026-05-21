// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "CapricornPlayerControllerBase.generated.h"

/**
 * 
 */

class UInputMappingContext;
class UInputAction;

UCLASS()
class CAPRICORN_API ACapricornPlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,Category = "增强输入")
	UInputMappingContext* DefautMappingContext;
	UPROPERTY(EditAnywhere,Category = "增强输入|动作")
	UInputAction* InteractAction;
	UPROPERTY(EditAnywhere,Category = "增强输入|动作")
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere,Category = "增强输入|动作")
	UInputAction* JumpAction;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	UFUNCTION(BlueprintCallable)
	void OnInteractPressed();
	UFUNCTION(BlueprintCallable)
	void OnMove(FInputActionValue InputActionValue);
	UFUNCTION(BlueprintCallable)
	void OnJumpPressed(FInputActionValue InputActionValue);
	
};
