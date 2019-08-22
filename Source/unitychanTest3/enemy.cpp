// Fill out your copyright notice in the Description page of Project Settings.


#include "enemy.h"
#include "unitychan.h"

// Sets default values
Aenemy::Aenemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Aenemy::BeginPlay()
{
	Super::BeginPlay();
	

	
	
}

// Called every frame
void Aenemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void Aenemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

