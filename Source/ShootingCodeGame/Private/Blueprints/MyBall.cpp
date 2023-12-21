// Fill out your copyright notice in the Description page of Project Settings.


#include "Blueprints/MyBall.h"

// Sets default values
AMyBall::AMyBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Myball");
	RootComponent = StaticMesh;
	StaticMesh->SetSimulatePhysics(true);
	SetReplicateMovement(true);
	bReplicates = true;
}

// Called when the game starts or when spawned
void AMyBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

