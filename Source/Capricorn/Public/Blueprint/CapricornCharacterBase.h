// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CapricornCharacterBase.generated.h"

enum class EInteractionType : uint8;
class UInteractionComponent;

UCLASS()
class CAPRICORN_API ACapricornCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY()
	UInteractionComponent* InteractionComponent;
	// Sets default values for this character's properties
	ACapricornCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION()
	void TryInteract (EInteractionType interactiontype);
	
};
