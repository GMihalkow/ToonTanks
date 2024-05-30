// Fill out your copyright notice in the Description page of Project Settings.

#include "ToonTanksGameMode.h"
#include "Pawns/Tank.h"
#include "Kismet/GameplayStatics.h"

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

	this->_tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this->GetWorld(), 0));
}

void AToonTanksGameMode::OnActorDied(const AActor* actor)
{
	if (actor != this->_tank) return;

	// TODO [GM]: execute player death clause

	UE_LOG(LogTemp, Log, TEXT("THE PLAYER JUST DIED!"));

	this->_playerDied = true;
}

bool AToonTanksGameMode::PlayerDied() const
{
	return this->_playerDied;
}
