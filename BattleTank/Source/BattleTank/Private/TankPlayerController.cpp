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
			// TODO tell controlled tank to aim at this point.
	}
}

// Get world location of linetrace through crosshair, true if it hits landscape.
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	// "De-project" the screen position of the crosshair to a world direction.
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) 
	{
		UE_LOG(LogTemp, Warning, TEXT("WorldDirection: %s"), *LookDirection.ToString());
	}
	// Line-trace along that look direction, and see what we hit (up to max range)
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // to be discarded
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
}