// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) 
	{ 
		UE_LOG(LogTemp, Error, TEXT("%s is not controlling any tank"), *GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is controlling %s"), *GetName(), *ControlledTank->GetName());
	}
}

//Tick
void ATankPlayerController::Tick(float DeltaSeconds)
{
	//Super
	Super::Tick(DeltaSeconds);

	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	//TODO PseudoCode here
}

