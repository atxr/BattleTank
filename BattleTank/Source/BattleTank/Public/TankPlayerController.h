// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;

	virtual void Tick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;

	// Get the position of the crosshair and start setting barrel and turret position 
	// in order to hit the intersection of the world and the crosshair if it exist 
	void AimTowardsCrosshair();
	
};
