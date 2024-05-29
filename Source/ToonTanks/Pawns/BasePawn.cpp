#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../Projectile.h"

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

void ABasePawn::RotateTurretTowards(const FVector& target, float speed)
{
	FVector direction = target - this->_body->GetComponentLocation();

	if (direction.Length() < 1.f) return;

	FRotator rotation = direction.Rotation();
	rotation.Pitch = 0.f;
	rotation.Roll = 0.f;

	FRotator newRotation = FMath::RInterpTo(this->_turret->GetComponentRotation(), rotation, UGameplayStatics::GetWorldDeltaSeconds(this), speed);
	this->_turret->SetWorldRotation(newRotation);
}

void ABasePawn::Fire()
{
	if (this->_projectileBlueprint != nullptr)
	{
		AProjectile* projectile = this->GetWorld()->SpawnActor<AProjectile>(this->_projectileBlueprint, this->_projectileSpawnPoint->GetComponentLocation(), this->_projectileSpawnPoint->GetComponentRotation());
		projectile->SetOwner(this->GetOwner());
	}

	DrawDebugSphere(this->GetWorld(), this->_projectileSpawnPoint->GetComponentLocation(), 10.f, 12, FColor::Red, false, 5.f);
}