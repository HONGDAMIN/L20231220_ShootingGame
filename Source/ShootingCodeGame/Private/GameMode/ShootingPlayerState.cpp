// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/ShootingPlayerState.h"
#include "Net/UnrealNetwork.h" // DOREPLIFETIME 사용을 위해 추가


void AShootingPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// 아래의 함수를 사용해서 서버에서 동기화를 시켜줍니다.
	DOREPLIFETIME(AShootingPlayerState, m_CurHp);
}


AShootingPlayerState::AShootingPlayerState():m_CurHp(100)
{
}

void AShootingPlayerState::AddDamage(float Damage)
{
}

void AShootingPlayerState::OnRep_CurHp()
{

	// 출력문을 통해서 변화값을 확인하기 위해 작성.
	// Print 문 안의 %f 는 m_CurHp 의 값.
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("OnRep_CurHp = %f"), m_CurHp));

	// 바인드가 걸려 있을때만 함수를 호출시키기 위한 조건문을 추가.
	if (m_Dele_UpdateHp.IsBound())
	{
		m_Dele_UpdateHp.Broadcast(m_CurHp, 100);
	}
}
