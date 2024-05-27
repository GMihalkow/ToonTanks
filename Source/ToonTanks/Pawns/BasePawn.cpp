// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/CapsuleComponent.h"
#include "BasePawn.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->_capsule = this->CreateDefaultSubobject<UCapsuleComponent>(TEXT("CAPSULE"));
	this->RootComponent = this->_capsule;

	this->_body = this->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	this->_body->AttachToComponent(this->_capsule, FAttachmentTransformRules::SnapToTargetIncludingScale);

	this->_turret = this->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TURRET"));
	this->_turret->AttachToComponent(this->_body, FAttachmentTransformRules::SnapToTargetIncludingScale);

	this->_projectileSpawnPoint = this->CreateDefaultSubobject<USceneComponent>(TEXT("PROJECTILES_SPAWN_POINT"));
	this->_projectileSpawnPoint->AttachToComponent(this->_turret, FAttachmentTransformRules::SnapToTargetIncludingScale);
}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}