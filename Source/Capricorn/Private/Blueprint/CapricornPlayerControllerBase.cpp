// Fill out your copyright notice in the Description page of Project Settings.


#include "Blueprint/CapricornPlayerControllerBase.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/CapricornCharacterBase.h"
#include "Interface/Interactable.h"

void ACapricornPlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();

	//注册输入映射上下文
	if(UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefautMappingContext,0);
	}
}

void ACapricornPlayerControllerBase::OnMove(FInputActionValue InputActionValue)
{
}

void ACapricornPlayerControllerBase::OnJumpPressed(FInputActionValue InputActionValue)
{
	
}

void ACapricornPlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();

	//转换为增强输入组件
	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent);
	if(!EIC) return;

	//绑定动作
	EIC->BindAction(InteractAction,ETriggerEvent::Started,this,&ACapricornPlayerControllerBase::OnInteractPressed);
	
}

void ACapricornPlayerControllerBase::OnInteractPressed()
{
	// 获取控制的 Character，调用其方法
	if(ACapricornCharacterBase* Char = Cast<ACapricornCharacterBase>(GetPawn()))
	{
		Char->TryInteract(EInteractionType::None);
	}
}

