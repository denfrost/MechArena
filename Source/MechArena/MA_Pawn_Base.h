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

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "MechArena")
	TSubclassOf<AMA_Actor_Weapon_Base> LeftStartingWeapon;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "MechArena")
	TSubclassOf<AMA_Actor_Weapon_Base> RightStartingWeapon;


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

	void Dash();

	bool IsDashing;
	float CurrentDashTime;
	float CurrentDashCooldownRemaining;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena")
	float DashDuration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena")
	float DashSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena")
	float DashCooldown;

	//bool IsLeftWeaponFiring;
	//bool IsRightWeaponFiring;

	float RotationSlowFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena")
	FVector FacingDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena")
	FVector AimingDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena")
	float MovementSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena")
	float RotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena")
	float StartingHealth;

};
