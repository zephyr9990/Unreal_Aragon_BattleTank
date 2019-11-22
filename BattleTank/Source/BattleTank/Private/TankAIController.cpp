// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

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
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
