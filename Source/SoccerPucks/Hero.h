// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Ball.h"
#include "Hero.generated.h"

UCLASS()
class SOCCERPUCKS_API AHero : public APawn
{
	GENERATED_BODY()


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
	float PUSH_FORCE;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
	float SHOOT_VELOCITY;

	// Sets default values for this pawn's properties
	AHero();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	ABall* ball;
	bool is_colliding_with_ball;

	UBoxComponent* box_component;
	USphereComponent* shoot_collider;

	UFUNCTION(BlueprintNativeEvent, Category = "Shoot Function")
	void OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void OnOverlapBegin_Implementation(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintNativeEvent, Category = "Not Shoot Function")
	void OnOverlapEnd(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	void OnOverlapEnd_Implementation(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void Shoot();

	//Input functions
	void Move_XAxis(float AxisValue);
	void Move_YAxis(float AxisValue);

	//Input variables
	FVector CurrentVelocity;
	bool bGrowing;

	float x_value;
	float y_value;
};
