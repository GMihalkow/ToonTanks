// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGameMode.generated.h"

/**
 *
 */
UCLASS()
class TOONTANKS_API AToonTanksGameMode : public AGameModeBase
{
	GENERATED_BODY()

private:
	class ATank* _tank;

	bool _playerDied = false;

protected:
	virtual void BeginPlay() override;

public:
	void OnActorDied(const AActor* actor);

	bool PlayerDied() const;
};
