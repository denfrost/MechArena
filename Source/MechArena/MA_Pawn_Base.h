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

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	class UMA_Pawn_MovementComponent* MyMovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena Pawn")
	AMA_Actor_Weapon_Base* LeftWeapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena Pawn")
	AMA_Actor_Weapon_Base* RightWeapon;

	virtual UPawnMovementComponent* GetMovementComponent() const override;

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

	void StartFireLeft();
	void StartFireRight();

	void EndFireLeft();
	void EndFireRight();

	bool IsLeftWeaponFiring;
	bool IsRightWeaponFiring;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena Pawn")
	float RotationSlowFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena Pawn")
	FVector FacingDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena Pawn")
	float MovementSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena Pawn")
	float RotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena Pawn")
	int32 Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MechArena Pawn")
	int32 StartingHealth;
	
};
