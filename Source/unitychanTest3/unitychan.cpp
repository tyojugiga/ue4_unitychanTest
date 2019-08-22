// Fill out your copyright notice in the Description page of Project Settings.

#include "unitychanTest3.h"
#include "unitychan.h"
#include "fire.h"
#include "Classes/Components/InputComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "Runtime/Engine/Classes/Engine/World.h"



// Sets default values
Aunitychan::Aunitychan()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	 

}

// Called when the game starts or when spawned
void Aunitychan::BeginPlay()
{
	Super::BeginPlay();

	unitychanPos = GetActorLocation();
}

// Called every frame
void Aunitychan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//方向転換
	direction = GetActorLocation() - unitychanPos;
	if(!direction.IsZero())
	{
		float unitychanDir = direction.X / (FMath::Sqrt(FMath::Pow(direction.X, 2.0f) + FMath::Pow(direction.Y, 2.0f)));
		float theta = FMath::Acos(unitychanDir);
		theta *= (180.0f / PI) * dValue;

		FRotator Theta(0.0f, theta, 0.0f);
		SetActorRotation(Theta);
	}
	unitychanPos = GetActorLocation();
	
}

// Called to bind functionality to input
void Aunitychan::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//移動
	PlayerInputComponent->BindAxis("moveF", this, &Aunitychan::moveF);
	PlayerInputComponent->BindAxis("moveR", this, &Aunitychan::moveR);

	//ジャンプ
	PlayerInputComponent->BindAction("jump", IE_Pressed, this, &Aunitychan::startJump);
	PlayerInputComponent->BindAction("jump", IE_Released, this, &Aunitychan::stopJump);

	//スピード変化
	PlayerInputComponent->BindAction("speedUp", IE_Pressed, this, &Aunitychan::speedUP);
	PlayerInputComponent->BindAction("speedUp", IE_Released, this, &Aunitychan::speedDOWN);

	//攻撃
	PlayerInputComponent->BindAction("fire", IE_Pressed, this, &Aunitychan::Fire);
}

void Aunitychan::moveF(float value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, value*speed);
	
	if(value>0)
	{
		dValue = 0;
	}
	else if(value<0)
	{
		dValue = 1.0f;
	}
}

void Aunitychan::moveR(float value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, value*speed);

	if(value<0)
	{
		dValue = -1.0f;
	}
	else if(value>0)
	{
		dValue = 1.0f;
	}
}

void Aunitychan::startJump()
{
	bPressedJump = true;
}

void Aunitychan::stopJump()
{
	bPressedJump = false;
}

void Aunitychan::speedUP()
{
	speed = 0.5f;
}

void Aunitychan::speedDOWN()
{
	speed = 0.2f;
}

void Aunitychan::Fire()
{
	if(ProjectileClass)
	{
		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);

		FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);
		FRotator MuzzleRotation = CameraRotation;

		

		UWorld* World = GetWorld();

		if(World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			Afire* Projectile = World->SpawnActor<Afire>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);

			if(Projectile)
			{
				FVector LaunchDirection = direction;
				Projectile->FireInDirection(LaunchDirection);
			}
		}
	}
}

