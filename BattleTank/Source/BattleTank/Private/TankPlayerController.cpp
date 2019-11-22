// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (GetControlledTank() == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("No player controlled tank on %s"), *GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is controlling tank: %s"),
			*GetName(), *GetControlledTank()->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector OutHitLocation; // Out parameter

	if (GetSightRayHitLocation(OutHitLocation)) // Has "side-effect", is going to line trace.
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *OutHitLocation.ToString());
			// TODO tell controlled tank to aim at this point.
	}
}

// Get world location of linetrace through crosshair, true if it hits landscape.
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;
}
