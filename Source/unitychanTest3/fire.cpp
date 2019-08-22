// Fill out your copyright notice in the Description page of Project Settings.

 
#include "fire.h"
#include "Classes/Components/SphereComponent.h"
#include "Engine.h"


UPROPERTY(VisibleDefaultsOnly, Category = fire)
USphereComponent* CollisionComponent;
UPROPERTY(VisibleAnywhere, Category = Movement)
UProjectileMovementComponent* ProjectileMovementComponent;



// Sets default values
Afire::Afire()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CollisionComponent->InitSphereRadius(15.0f);
	RootComponent = CollisionComponent;


	//èâä˙ê›íË
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
	ProjectileMovementComponent->InitialSpeed = 2000.0f;
	ProjectileMovementComponent->MaxSpeed = 2000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = true;
	ProjectileMovementComponent->Bounciness = 0.3f;
}

// Called when the game starts or when spawned
void Afire::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Afire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Afire::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;

}

