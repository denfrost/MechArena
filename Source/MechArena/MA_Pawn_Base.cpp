// Fill out your copyright notice in the Description page of Project Settings.

#include "MechArena.h"
#include "Kismet/KismetMathLibrary.h"
#include "MA_Pawn_MovementComponent.h"
#include "MA_Pawn_Base.h"


// Sets default values
AMA_Pawn_Base::AMA_Pawn_Base()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyMovementComponent = CreateDefaultSubobject<UMA_Pawn_MovementComponent>(TEXT("MAMovementComponent"));
	MyMovementComponent->UpdatedComponent = RootComponent;
}

// Called when the game starts or when spawned
void AMA_Pawn_Base::BeginPlay()
{
	Super::BeginPlay();

	Health = StartingHealth;
	IsDashing = false;
	
}

// Called every frame
void AMA_Pawn_Base::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	CurrentDashCooldownRemaining -= DeltaTime;

	if (!IsDashing)
	{
		FRotator targetRotation = UKismetMathLibrary::FindLookAtRotation(FVector(0.0f), FacingDirection);

		SetActorRotation(UKismetMathLibrary::RInterpTo_Constant(GetActorRotation(), targetRotation, DeltaTime, RotationSpeed));

		float rotDiff = FVector::DotProduct(FacingDirection.GetSafeNormal(), GetActorRotation().Vector());

		if (rotDiff >= 0.999f)
		{
			RotationSlowFactor = 1.0f;
		}
		else if (rotDiff > 0.8f)
		{
			RotationSlowFactor = 1.0f - rotDiff;
		}
		else
		{
			RotationSlowFactor = 0.0f;
		}
	}
	else
	{
		if (CurrentDashTime < 0.0f)
		{
			IsDashing = false;
			CurrentDashCooldownRemaining = DashCooldown;
		}
		else
		{
			MyMovementComponent->AddInputVector(FacingDirection.GetSafeNormal() * DashSpeed);
			CurrentDashTime -= DeltaTime;
		}

	}
		
}

UPawnMovementComponent* AMA_Pawn_Base::GetMovementComponent() const
{
	return MyMovementComponent;
}

void AMA_Pawn_Base::OnBeginFireLeftWeapon()
{
	if (LeftWeapon)
	{
		LeftWeapon->OnBeginFire();
	}
}

void AMA_Pawn_Base::OnBeginFireRightWeapon()
{
	if (RightWeapon)
	{
		RightWeapon->OnBeginFire();
	}
}

void AMA_Pawn_Base::OnEndFireLeftWeapon()
{
	if (LeftWeapon)
	{
		LeftWeapon->OnEndFire();
	}
}

void AMA_Pawn_Base::OnEndFireRightWeapon()
{
	if (RightWeapon)
	{
		RightWeapon->OnEndFire();
	}
}

void AMA_Pawn_Base::MoveForward(float aAxisValue)
{
	if (MyMovementComponent && (MyMovementComponent->UpdatedComponent == RootComponent) && !IsDashing)
	{
		MyMovementComponent->AddInputVector(FVector::ForwardVector * aAxisValue * MovementSpeed * RotationSlowFactor);
		if (FMath::Abs(aAxisValue) > 0.1f)
		{
			FacingDirection.X = aAxisValue;
		}

	}
}

void AMA_Pawn_Base::MoveRight(float aAxisValue)
{
	if (MyMovementComponent && (MyMovementComponent->UpdatedComponent == RootComponent) && !IsDashing)
	{
		MyMovementComponent->AddInputVector(FVector::RightVector * aAxisValue * MovementSpeed * RotationSlowFactor);
		if (FMath::Abs(aAxisValue) > 0.1f)
		{
			FacingDirection.Y = aAxisValue;
		}
	}
}

void AMA_Pawn_Base::AimForward(float aAxisValue)
{
	if (FMath::Abs(aAxisValue) > 0.1f)
	{
		AimingDirection.X = aAxisValue;
	}
}

void AMA_Pawn_Base::AimRight(float aAxisValue)
{
	if (FMath::Abs(aAxisValue) > 0.1f)
	{
		AimingDirection.Y = aAxisValue;
	}
}

void AMA_Pawn_Base::Dash()
{
	if (CurrentDashCooldownRemaining > 0.0f)
	{
		return;
	}
	// Get the rotation we are aiming for on the stick
	FRotator targetRotation = UKismetMathLibrary::FindLookAtRotation(FVector(0.0f), FacingDirection);

	// Switch to it immediately
	SetActorRotation(targetRotation);

	CurrentDashTime = DashDuration;
	IsDashing = true;

}
