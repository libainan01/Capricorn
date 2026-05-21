// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Kitchenware.h"

#include "Actor/Ingredients.h"
#include "Component/ActorComponent/InteractionComponent.h"

// Sets default values
AKitchenware::AKitchenware()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoddyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoddyMesh"));
	BoddyMesh->SetupAttachment(RootComponent);

}

bool AKitchenware::TryAddIngredient(AIngredients* TargetIngredients)
{
	for (auto targetState : AllowState)
	{
		if(targetState == TargetIngredients->CurrentState) return true;
	}
	return false;	
}

bool AKitchenware::TryRemoveIngredient()
{
	return false;
}

EInteractionType AKitchenware::Interact(AActor* Interactor,EInteractionType InteractionType)
{
	//获得交互
	return EInteractionType::None;
}

TArray<EInteractionType> AKitchenware::GetAvailableInteractions(AActor* Interactor)
{
	TArray<EInteractionType> temp;
	return temp;
}

void AKitchenware::OnInteractableCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                                       UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFormSweep, const FHitResult& SweepResult)
{
	TArray<UInteractionComponent*> InteractionComponents;
	OtherActor->GetComponents<UInteractionComponent>(InteractionComponents);
	if(!InteractionComponents.IsEmpty())
	{
		InteractionComponents[0]->InteractiveObjects.AddUnique(this);
	}
}

void AKitchenware::OnInteractableCollisionEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	TArray<UInteractionComponent*> InteractionComponents;
	OtherActor->GetComponents<UInteractionComponent>(InteractionComponents);
	if(!InteractionComponents.IsEmpty())
	{
		InteractionComponents[0]->InteractiveObjects.Remove(this);
	}
}

bool AKitchenware::CanAddIngredient()
{
	return false;
}

bool AKitchenware::OnProcessFinished()
{
	return false;
}

// Called when the game starts or when spawned
void AKitchenware::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKitchenware::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

