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

}
