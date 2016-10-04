// Fill out your copyright notice in the Description page of Project Settings.

#include "MechArena.h"
#include "MA_Pawn_Base.h"
#include "MA_PlayerController_Base.h"




void AMA_PlayerController_Base::SetupInputComponent()
{
	Super::SetupInputComponent();

	check(InputComponent);

	InputComponent->BindAxis("MoveForward", this, &AMA_PlayerController_Base::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMA_PlayerController_Base::MoveRight);

	InputComponent->BindAxis("AimForward", this, &AMA_PlayerController_Base::AimForward);
	InputComponent->BindAxis("AimRight", this, &AMA_PlayerController_Base::AimRight);

	InputComponent->BindAction("FireLeft", IE_Pressed, this, &AMA_PlayerController_Base::StartFireLeft);
	InputComponent->BindAction("FireRight", IE_Pressed, this, &AMA_PlayerController_Base::StartFireRight);
	InputComponent->BindAction("FireLeft", IE_Released, this, &AMA_PlayerController_Base::EndFireLeft);
	InputComponent->BindAction("FireRight", IE_Released, this, &AMA_PlayerController_Base::EndFireRight);

	InputComponent->BindAction("RespawnPawn", IE_Pressed, this, &AMA_PlayerController_Base::RespawnPawn);

}

void AMA_PlayerController_Base::Possess(APawn* aPawn)
{
	Super::Possess(aPawn);

	MyPawn = Cast<AMA_Pawn_Base>(aPawn);

}


void AMA_PlayerController_Base::MoveForward(float AxisValue)
{
	if (MyPawn)
	{
		MyPawn->MoveForward(AxisValue);
	}
}

void AMA_PlayerController_Base::MoveRight(float AxisValue)
{
	if (MyPawn)
	{
		MyPawn->MoveRight(AxisValue);
	}
}

void AMA_PlayerController_Base::AimForward(float AxisValue)
{
	if (MyPawn)
	{
		MyPawn->AimForward(AxisValue);
	}
}

void AMA_PlayerController_Base::AimRight(float AxisValue)
{
	if (MyPawn)
	{
		MyPawn->AimRight(AxisValue);
	}

}

void AMA_PlayerController_Base::StartFireLeft()
{
	if (MyPawn)
	{
		MyPawn->OnBeginFireLeftWeapon();
	}
}

void AMA_PlayerController_Base::StartFireRight()
{
	if (MyPawn)
	{
		MyPawn->OnBeginFireRightWeapon();
	}
}

void AMA_PlayerController_Base::EndFireLeft()
{
	if (MyPawn)
	{
		MyPawn->OnEndFireLeftWeapon();
	}
}

void AMA_PlayerController_Base::EndFireRight()
{
	if (MyPawn)
	{
		MyPawn->OnEndFireRightWeapon();
	}
}

void AMA_PlayerController_Base::RespawnPawn()
{
	OnRespawnPawn();
}

