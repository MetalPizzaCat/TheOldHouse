// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "PickapableActorBase.h"
#include "UObject/Interface.h"
#include "Interaction.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteraction : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OLDHOUSE_API IInteraction
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent,Category= Interaction)
	void Interact(AActor*Interactor);

	UFUNCTION(BlueprintCallable,BlueprintNativeEvent,Category= "Interaction|Display")
	void DisplayInteractionText(const FText& Text);

	UFUNCTION(BlueprintCallable,BlueprintNativeEvent,Category= "Interaction|Pickup")
	bool PickupActor(APickapableActorBase*Actor);
};
