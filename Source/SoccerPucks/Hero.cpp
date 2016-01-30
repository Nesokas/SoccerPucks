// Fill out your copyright notice in the Description page of Project Settings.

#include "SoccerPucks.h"
#include "Hero.h"

// Sets default values
AHero::AHero()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set this pawn to be controlled by the lowest-numbered player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void AHero::BeginPlay()
{
	Super::BeginPlay();

	TArray<UBoxComponent*> all_box_components;
	GetComponents(all_box_components);

	for (UBoxComponent* box_comp : all_box_components)
	{
		box_component = box_comp;
	}
}

// Called every frame
void AHero::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	const FVector MoveDirection = FVector(x_value, y_value, 0.f).GetClampedToMaxSize(1.0f);
	//const float MoveSpeed = 20.0f;
	
	if (box_component != NULL) {
		//push_force = 9990000.0f
		const FVector Movement = MoveDirection * push_force;
		GEngine->AddOnScreenDebugMessage(0, 15.0f, FColor::Red, box_component->GetPhysicsLinearVelocity().ToString() /*Movement.ToString()*/);
		if (Movement.SizeSquared() > 0.0f)
		{
			box_component->AddForce(Movement);
		}
	}

}

// Called to bind functionality to input
void AHero::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	// Respond every frame to the values of our two movement axes, "MoveX" and "MoveY".
	InputComponent->BindAxis("MoveX", this, &AHero::Move_XAxis);
	InputComponent->BindAxis("MoveY", this, &AHero::Move_YAxis);
}

void AHero::Move_XAxis(float AxisValue)
{
	x_value = AxisValue;
}

void AHero::Move_YAxis(float AxisValue)
{
	y_value = AxisValue;
}