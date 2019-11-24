// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (GetControlledTank() == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("No AI controlled tank on %s."), *GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is controlling %s."), *GetName(), *GetControlledTank()->GetName());
	}

	if (GetPlayerTank() == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't get player tank."))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s got player: %s"), *GetName(), *GetPlayerTank()->GetName())
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// TODO Move towards the player.
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		// TODO Fire if ready.
	}
}
