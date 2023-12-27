// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ShootingHudWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTINGCODEGAME_API AShootingHudWidget : public AHUD
{
	GENERATED_BODY()
	
public://BeginPlay���� HUD �۾��� �̾� ���� ���ؼ� �߰�
	virtual void BeginPlay();

public:
	//TSubclassOf : ������ Ŭ������ Ŭ������ ����� ��� Ŭ������ ���� �����ϴ�.
	// �ٽø��� UUserWidget Ŭ������ �� Ŭ������ ����� ��� Ŭ������ ���� �����ϴٴ� ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUserWidget> HudWidgetClass;

	//������ ������ �����ϱ� ���� ����
	UPROPERTY(BlueprintReadWrite)
	UUserWidget* HudWidget;
};
