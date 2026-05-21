// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/ActorComponent/UItemHolderComponent.h"

// Sets default values for this component's properties
UUItemHolderComponent::UUItemHolderComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UUItemHolderComponent::AddActor(AActor* TargetActor)
{
	Effect = TargetActor;
}

void UUItemHolderComponent::RemoveActor()
{
	Effect = nullptr;
}

bool UUItemHolderComponent::isEmpty() const 
{
	if(Effect == nullptr) return true;
	return false;
}


// Called when the game starts
void UUItemHolderComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UUItemHolderComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

