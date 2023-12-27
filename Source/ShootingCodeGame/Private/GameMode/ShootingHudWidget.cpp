// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/ShootingHudWidget.h"
#include "Blueprint/UserWidget.h"

void AShootingHudWidget::BeginPlay()
{
	Super::BeginPlay();

	//이걸 입력하면 에러가 발생한 위치를 알려준다.
	check(HudWidgetClass);

	HudWidget = CreateWidget<UUserWidget>(GetWorld(), HudWidgetClass);
	HudWidget->AddToViewport();
}
