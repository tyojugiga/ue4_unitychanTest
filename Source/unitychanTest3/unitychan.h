// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "unitychan.generated.h"

UCLASS()
class UNITYCHANTEST3_API Aunitychan : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	Aunitychan();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void moveF(float value);

	UFUNCTION()
	void moveR(float value);

	UFUNCTION()
		void startJump();

	UFUNCTION()
		void stopJump();

	UFUNCTION()
		void speedUP();

	UFUNCTION()
		void speedDOWN();

	UFUNCTION()
		void Fire();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector MuzzleOffset;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class Afire> ProjectileClass;

	float speed = 0.2f;
	FVector unitychanPos;
	FVector direction;
	float dValue = 0;
};
