// Fill out your copyright notice in the Description page of Project Settings.

#include "SoccerPucks.h"
#include "Ball.h"


// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
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
void ABall::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ABall::AddVelocity(FVector direction, float velocity)
{
	FVector impulse = direction*velocity;
//	UE_LOG(LogTemp, Warning, TEXT("%f %f %f"), impulse.X, impulse.Y, impulse.Z);
	box_component->AddImpulse(impulse);
}

