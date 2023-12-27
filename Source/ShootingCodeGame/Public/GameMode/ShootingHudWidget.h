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
	
public://BeginPlay에서 HUD 작업을 이어 가기 위해서 추가
	virtual void BeginPlay();

public:
	//TSubclassOf : 지정한 클래스와 클래스를 상속한 모든 클래스를 지정 가능하다.
	// 다시말해 UUserWidget 클래스와 이 클래스를 상속한 모든 클래스를 지정 가능하다는 뜻
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUserWidget> HudWidgetClass;

	//생성된 위젯을 저장하기 위한 변수
	UPROPERTY(BlueprintReadWrite)
	UUserWidget* HudWidget;
};
