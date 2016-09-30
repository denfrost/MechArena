// Fill out your copyright notice in the Description page of Project Settings.

#include "MechArena.h"
#include "MA_Actor_Weapon_Base.h"


// Sets default values
AMA_Actor_Weapon_Base::AMA_Actor_Weapon_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMA_Actor_Weapon_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMA_Actor_Weapon_Base::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


