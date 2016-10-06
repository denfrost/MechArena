// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "MA_PlayerController_Base.generated.h"

/**
 * 
 */
UCLASS()
class MECHARENA_API AMA_PlayerController_Base : public APlayerController
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AMA_Pawn_Base* MyPawn;

	virtual void SetupInputComponent() override;

	virtual void Possess(APawn* aPawn) override;
	
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

	void AimForward(float AxisValue);
	void AimRight(float AxisValue);

	void StartFireLeft();
	void StartFireRight();

	void EndFireLeft();
	void EndFireRight();

	void RespawnPawn();
	void Dash();

	UFUNCTION(BlueprintImplementableEvent, Category ="MechArena")
	void OnRespawnPawn();

	UFUNCTION(BlueprintImplementableEvent, Category = "MechArena")
	void OnDash();
	
};
