// Fill out your copyright notice in the Description page of Project Settings.


#include "Blueprints/Weapon.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//스태틱매쉬 추가, 이름은 Weapon 루트컴포넌트를 웨폰매쉬로
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("Weapon");
	SetRootComponent(WeaponMesh);
	//리플리케이티드 트루,리플리케이트무브먼트 트루
	bReplicates = true;
	SetReplicateMovement(true);

}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

