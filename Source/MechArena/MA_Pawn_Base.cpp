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
	
}

// Called every frame
void AMA_Pawn_Base::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FRotator targetRotation = UKismetMathLibrary::FindLookAtRotation(FVector(0.0f), FacingDirection);

	SetActorRotation(UKismetMathLibrary::RInterpTo_Constant(GetActorRotation(), targetRotation, DeltaTime, RotationSpeed));
	
	//SetActorRotation(FMath::Lerp(GetActorRotation(), targetRotation, RotationSpeed));

	float rotDiff = FVector::DotProduct(FacingDirection.GetSafeNormal(), GetActorRotation().Vector());

	if ( rotDiff >= 0.999f)
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

// Called to bind functionality to input
void AMA_Pawn_Base::SetupPlayerInputComponent(class UInputComponent* aInputComponent)
{
	Super::SetupPlayerInputComponent(aInputComponent);

	aInputComponent->BindAxis("MoveForward", this, &AMA_Pawn_Base::MoveForward);
	aInputComponent->BindAxis("MoveRight", this, &AMA_Pawn_Base::MoveRight);

	aInputComponent->BindAxis("AimForward", this, &AMA_Pawn_Base::AimForward);
	aInputComponent->BindAxis("AimRight", this, &AMA_Pawn_Base::AimRight);

	aInputComponent->BindAction("FireLeft", IE_Pressed, this, &AMA_Pawn_Base::StartFireLeft);
	aInputComponent->BindAction("FireRight", IE_Pressed, this, &AMA_Pawn_Base::StartFireRight);
	aInputComponent->BindAction("FireLeft", IE_Released, this, &AMA_Pawn_Base::EndFireLeft);
	aInputComponent->BindAction("FireRight", IE_Released, this, &AMA_Pawn_Base::EndFireRight);

}

UPawnMovementComponent* AMA_Pawn_Base::GetMovementComponent() const
{
	return MyMovementComponent;
}

void AMA_Pawn_Base::MoveForward(float AxisValue)
{
	if (MyMovementComponent && (MyMovementComponent->UpdatedComponent == RootComponent))
	{
		MyMovementComponent->AddInputVector(FVector::ForwardVector * AxisValue * MovementSpeed * RotationSlowFactor);
		if (FMath::Abs(AxisValue) > 0.1f)
		{
			FacingDirection.X = AxisValue;
		}
		
	}
}

void AMA_Pawn_Base::MoveRight(float AxisValue)
{
	if (MyMovementComponent && (MyMovementComponent->UpdatedComponent == RootComponent))
	{
		MyMovementComponent->AddInputVector(FVector::RightVector * AxisValue * MovementSpeed * RotationSlowFactor);
		if (FMath::Abs(AxisValue) > 0.1f)
		{
			FacingDirection.Y = AxisValue;
		}
	}
}

void AMA_Pawn_Base::AimForward(float AxisValue)
{
	if (FMath::Abs(AxisValue) > 0.1f)
	{
		AimingDirection.X = AxisValue;
	}
}

void AMA_Pawn_Base::AimRight(float AxisValue)
{
	if (FMath::Abs(AxisValue) > 0.1f)
	{
		AimingDirection.Y = AxisValue;
	}
}

void AMA_Pawn_Base::StartFireLeft()
{
	if (LeftWeapon)
	{
		LeftWeapon->OnBeginFire();
	}
}

void AMA_Pawn_Base::StartFireRight()
{
	if (RightWeapon)
	{
		RightWeapon->OnBeginFire();
	}
}

void AMA_Pawn_Base::EndFireLeft()
{
	if (LeftWeapon)
	{
		LeftWeapon->OnEndFire();
	}
}

void AMA_Pawn_Base::EndFireRight()
{
	if (RightWeapon)
	{
		RightWeapon->OnEndFire();
	}
}


