// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/ShootingHudWidget.h"
#include "Blueprint/UserWidget.h"

void AShootingHudWidget::BeginPlay()
{
	Super::BeginPlay();

	//�̰� �Է��ϸ� ������ �߻��� ��ġ�� �˷��ش�.
	check(HudWidgetClass);

	HudWidget = CreateWidget<UUserWidget>(GetWorld(), HudWidgetClass);
	HudWidget->AddToViewport();
}
