// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/ShootingHudWidget.h"
#include "Blueprint/UserWidget.h"
#include "GameMode/ShootingPlayerState.h"//PlayerState를 가져오기 위해서 


void AShootingHudWidget::BeginPlay()
{
	Super::BeginPlay();

	//이걸 입력하면 에러가 발생한 위치를 알려준다.
	check(HudWidgetClass);

	HudWidget = CreateWidget<UUserWidget>(GetWorld(), HudWidgetClass);
	HudWidget->AddToViewport();

	BindMyPlayerState(); //BeginPlay에서 바인딩 작업
}

void AShootingHudWidget::BindMyPlayerState()
{
	// GetFirstPlayerController 이 PlayerController 에서 0 번째를 가져오는 방법.
	APlayerController* pc = GetWorld()->GetFirstPlayerController();
	if (IsValid(pc))
	{
		// 캐릭터의 PlayerState 를 형변환을 통해 가져옴.
		AShootingPlayerState* ps = Cast<AShootingPlayerState>(pc->PlayerState);
		if (IsValid(ps))
		{
			// 가져온 PlayerState 인 ps 에 바인딩 해줄 이벤트를 지정해줍니다.(주소로 함수명을 건다.)
			ps->m_Dele_UpdateHp.AddDynamic(this, &AShootingHudWidget::OnUpdateMyHP);
			OnUpdateMyHP(ps->m_CurHp, 100);//바인딩 성공시 초기 Hp 값 세팅
			GEngine->AddOnScreenDebugMessage(-1, 15.01f, FColor::Blue, TEXT("AShootingHudWidget(ps) Bind Success"));
			return;
		}
	}

	FTimerManager& timerManager = GetWorld()->GetTimerManager();
	// 타이머 세팅 - 타이머 변수, 하는 행위 PlayerController 0번 즉 자기 자신, 시간은 0.01초 후에, 반복은 하지 않음
	timerManager.SetTimer(th_BindMyPlayerState, this, &AShootingHudWidget::BindMyPlayerState, 0.01f, false);
}


void AShootingHudWidget::OnUpdateMyHP_Implementation(float CuerHP, float MaxHP)
{
}
