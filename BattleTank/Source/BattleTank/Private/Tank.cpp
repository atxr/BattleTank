// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

// Sets default values
ATank::ATank() : bMoveForward(false)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (bMoveForward)
	{
		GetWorld()->GetFirstPlayerController();

		FVector const NewLocation = GetActorLocation() + FVector(10, 0, 0);
		SetActorLocation(NewLocation);
	}
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("MoveForward", IE_Pressed, this, &ATank::StartMoveForward);
	InputComponent->BindAction("MoveForward", IE_Released, this, &ATank::StopMoveForward);
}

void ATank::StartMoveForward() { bMoveForward = true; }
void ATank::StopMoveForward() { bMoveForward = false; }

