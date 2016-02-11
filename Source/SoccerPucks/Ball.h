// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Ball.generated.h"

UCLASS()
class SOCCERPUCKS_API ABall : public AActor
{
	GENERATED_BODY()

private:

	USphereComponent* horizontal_collider;
	
public:	
	// Sets default values for this actor's properties
	ABall();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void AddVelocity(FVector direction, float velocity);

	
	
};
