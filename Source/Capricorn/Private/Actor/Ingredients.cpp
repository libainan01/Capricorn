// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Ingredients.h"

#include "Blueprint/CapricornCharacterBase.h"
#include "Component/ActorComponent/InteractionComponent.h"
#include "Component/ActorComponent/UItemHolderComponent.h"
#include "Components/SphereComponent.h"


bool AIngredients::TryTransition(EIngredientState TargetIngredientState)
{
	FIngredientState _ingredientStates = *IngredientData->Transitions.Find(CurrentState);
	for (auto _ingredientstate: _ingredientStates.IngredientStates)
	{
		if (_ingredientstate == TargetIngredientState)
		{
			CurrentState = TargetIngredientState;
			UpdateStaticMesh(TargetIngredientState);
			return true;
		}
	}
	//这里可以根据CurrentState来输出不同的内容
	return false;
}

EInteractionType AIngredients::Interact(AActor* Interactor,EInteractionType InteractionType)
{
	//先拿到交互组件
	TArray<UInteractionComponent*> InteractionComponents;
	Interactor->GetComponents<UInteractionComponent>(InteractionComponents);
	if(InteractionComponents.IsEmpty()) UE_LOG(LogTemp,Error,TEXT("找不到交互组件"))
	//依据手中是否有物品，来决定交互行为
	if(InteractionComponents[0]->HolderSlot->isEmpty())
	{
		InteractionComponents[0]->InteractiveObjects.Remove(this);
		return EInteractionType::PickUp;
	}
	return EInteractionType::PutDown;
}

TArray<EInteractionType> AIngredients::GetAvailableInteractions(AActor* Interactor)
{
	
	TArray<EInteractionType> temp;
	return temp;
}

void AIngredients::OnInteractionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFormSweep, const FHitResult& SweepResult)
{
	TArray<UInteractionComponent*> InteractionComponents;
	OtherActor->GetComponents<UInteractionComponent>(InteractionComponents);
	if(!InteractionComponents.IsEmpty())
	{
		InteractionComponents[0]->InteractiveObjects.AddUnique(this);
	}
}
void AIngredients::OnInteractionSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	TArray<UInteractionComponent*> InteractionComponents;
	OtherActor->GetComponents<UInteractionComponent>(InteractionComponents);
	if(!InteractionComponents.IsEmpty())
	{
		InteractionComponents[0]->InteractiveObjects.Remove(this);
	}
}

// Sets default values
AIngredients::AIngredients()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoddyMesh"));
	StaticMeshComponent->SetupAttachment(RootComponent);
	InteractableCollision = CreateDefaultSubobject<USphereComponent>(TEXT("InteractableCollision"));
	InteractableCollision->SetupAttachment(StaticMeshComponent);
}

// Called when the game starts or when spawned
void AIngredients::BeginPlay()
{
	Super::BeginPlay();
	InteractableCollision->OnComponentBeginOverlap.AddDynamic(this,&AIngredients::OnInteractionSphereBeginOverlap);
	InteractableCollision->OnComponentEndOverlap.AddDynamic(this,&AIngredients::OnInteractionSphereEndOverlap);
}

void AIngredients::UpdateStaticMesh(EIngredientState TargetIngredinetState)
{
	if(!*IngredientData->StateMeshes.Find(TargetIngredinetState)) return;
	StaticMeshComponent->SetStaticMesh(*IngredientData->StateMeshes.Find(TargetIngredinetState));
}

void AIngredients::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if(PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(AIngredients,IngredientData))
	{
		if(!IngredientData) return;
		UpdateStaticMesh(CurrentState);
	}
}

// Called every frame
void AIngredients::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

