// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "WeaponType.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

UCLASS()
class OLDHOUSE_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category= Owner)
	AActor*OwnerWhoFires = nullptr;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category= Socket)
	FString HolsterSocketName;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category= Socket)
	FVector HolsterLocationOffset = FVector::ZeroVector;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category= Socket)
	FRotator HolsterRotationOffset = FRotator::ZeroRotator;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category= Type)
	EWeaponType Type = EWeaponType::EWT_Melee;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category= Damage)
	float Damage = 0.f;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category= Damage)
	TSubclassOf<UDamageType> DamageType;

	/*For weapons that shoot*/
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent,Category= Fire)
	void Fire(FVector Location,FRotator Rotation);

	/*For melee weapons*/
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent,Category= Attack)
	void Attack(UAnimMontage*AttackAnim);
	
};
