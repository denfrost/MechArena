// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MA_Actor_Weapon_Base.generated.h"

UCLASS()
class MECHARENA_API AMA_Actor_Weapon_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMA_Actor_Weapon_Base();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena Weapon")
	int32 AmmoCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MechArena Weapon")
	int32 MaxAmmoCount;

	UFUNCTION(BlueprintImplementableEvent, Category = "MechArena Weapon")
	void OnBeginFire();

	UFUNCTION(BlueprintImplementableEvent, Category = "MechArena Weapon")
	void OnEndFire();

	UFUNCTION(BlueprintCallable, Category = "MechArena")
	void ReplenishAmmo();

};
