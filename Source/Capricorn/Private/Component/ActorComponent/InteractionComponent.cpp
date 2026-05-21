// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/Component/ActorComponent/InteractionComponent.h"

#include "Component/ActorComponent/UItemHolderComponent.h"
#include "Interface/Interactable.h"


// Sets default values for this component's properties
UInteractionComponent::UInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


void UInteractionComponent::TryInteract(EInteractionType interactiontype,AActor* Interactor)
{
	//TODO:这里还没有考虑多个可交互物重叠时的处理方案，暂时只交互数组中第一个物体

	AActor* InteractionActor = InteractiveObjects[0];
	
	
}

// Called when the game starts
void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

