// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "MA_Actor_Weapon_Base.h"
#include "MA_Pawn_Base.generated.h"

UCLASS()
class MECHARENA_API AMA_Pawn_Base : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMA_Pawn_Base();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	class UMA_Pawn_MovementComponent* MyMovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena Pawn")
	AMA_Actor_Weapon_Base* LeftWeapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena Pawn")
	AMA_Actor_Weapon_Base* RightWeapon;

	virtual UPawnMovementComponent* GetMovementComponent() const override;

	void OnBeginFireLeftWeapon();
	void OnBeginFireRightWeapon();
	void OnEndFireLeftWeapon();
	void OnEndFireRightWeapon();

	void MoveForward(float aAxisValue);
	void MoveRight(float aAxisValue);
	void AimForward(float aAxisValue);
	void AimRight(float aAxisValue);

	bool IsLeftWeaponFiring;
	bool IsRightWeaponFiring;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena Pawn")
	float RotationSlowFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena Pawn")
	FVector FacingDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena Pawn")
	FVector AimingDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena Pawn")
	float MovementSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena Pawn")
	float RotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena Pawn")
	int32 Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena Pawn")
	int32 StartingHealth;

};
