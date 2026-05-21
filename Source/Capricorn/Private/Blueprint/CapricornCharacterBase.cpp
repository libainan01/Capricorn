// Fill out your copyright notice in the Description page of Project Settings.


#include "Blueprint/CapricornCharacterBase.h"
#include "Component/ActorComponent/InteractionComponent.h"

// Sets default values
ACapricornCharacterBase::ACapricornCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	InteractionComponent = CreateDefaultSubobject<UInteractionComponent>(TEXT("InteractionComponent"));
}

// Called when the game starts or when spawned
void ACapricornCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACapricornCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACapricornCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACapricornCharacterBase::TryInteract(EInteractionType interactiontype)
{
	InteractionComponent->TryInteract(interactiontype,this);
}
