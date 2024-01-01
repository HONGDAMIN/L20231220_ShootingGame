// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/ShootingHudWidget.h"
#include "Blueprint/UserWidget.h"
#include "GameMode/ShootingPlayerState.h"//PlayerState�� �������� ���ؼ� 


void AShootingHudWidget::BeginPlay()
{
	Super::BeginPlay();

	//�̰� �Է��ϸ� ������ �߻��� ��ġ�� �˷��ش�.
	check(HudWidgetClass);

	HudWidget = CreateWidget<UUserWidget>(GetWorld(), HudWidgetClass);
	HudWidget->AddToViewport();

	BindMyPlayerState(); //BeginPlay���� ���ε� �۾�
}

void AShootingHudWidget::BindMyPlayerState()
{
	// GetFirstPlayerController �� PlayerController ���� 0 ��°�� �������� ���.
	APlayerController* pc = GetWorld()->GetFirstPlayerController();
	if (IsValid(pc))
	{
		// ĳ������ PlayerState �� ����ȯ�� ���� ������.
		AShootingPlayerState* ps = Cast<AShootingPlayerState>(pc->PlayerState);
		if (IsValid(ps))
		{
			// ������ PlayerState �� ps �� ���ε� ���� �̺�Ʈ�� �������ݴϴ�.(�ּҷ� �Լ����� �Ǵ�.)
			ps->m_Dele_UpdateHp.AddDynamic(this, &AShootingHudWidget::OnUpdateMyHP);
			OnUpdateMyHP(ps->m_CurHp, 100);//���ε� ������ �ʱ� Hp �� ����
			GEngine->AddOnScreenDebugMessage(-1, 15.01f, FColor::Blue, TEXT("AShootingHudWidget(ps) Bind Success"));
			return;
		}
	}

	FTimerManager& timerManager = GetWorld()->GetTimerManager();
	// Ÿ�̸� ���� - Ÿ�̸� ����, �ϴ� ���� PlayerController 0�� �� �ڱ� �ڽ�, �ð��� 0.01�� �Ŀ�, �ݺ��� ���� ����
	timerManager.SetTimer(th_BindMyPlayerState, this, &AShootingHudWidget::BindMyPlayerState, 0.01f, false);
}


void AShootingHudWidget::OnUpdateMyHP_Implementation(float CuerHP, float MaxHP)
{
}
