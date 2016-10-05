// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MA_Pickup_Base.generated.h"

UENUM(BlueprintType)		
enum class EMA_PickupType : uint8
{
	Ammo 	UMETA(DisplayName = "Ammo"),
	Health 	UMETA(DisplayName = "Health"),
	Weapon	UMETA(DisplayName = "Weapon")
};

UCLASS()
class MECHARENA_API AMA_Pickup_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMA_Pickup_Base();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena" )
	EMA_PickupType PickupType;
	
};
