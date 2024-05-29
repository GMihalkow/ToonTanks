// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	this->_mesh = this->CreateDefaultSubobject<UStaticMeshComponent>("MESH");
	this->RootComponent = this->_mesh;

	this->_movement = this->CreateDefaultSubobject<UProjectileMovementComponent>("MOVEMENT");
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	this->_mesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::OnHit(UPrimitiveComponent* hitComponent, AActor* otherActor, UPrimitiveComponent* other, FVector impulse, const FHitResult& hit)
{
	if (otherActor == nullptr || otherActor == this || otherActor == this->GetOwner())
	{
		return;
	}

	AController* instigator = otherActor->GetInstigatorController();
	UClass* dmgType = UDamageType::StaticClass();

	UGameplayStatics::ApplyDamage(otherActor, this->_damage, instigator, this, dmgType);

	Destroy();
}