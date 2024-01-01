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
	virtual void BeginPlay() override;

public:
	void BindMyPlayerState();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)//언리얼용 함수.
		void OnUpdateMyHP(float CuerHP, float MaxHP);// Implementation 함수를 cpp에 정의해주었으면 이건 정의하면 안됨... 이중 정의가 되서 빌드실패
		void OnUpdateMyHP_Implementation(float CuerHP, float MaxHP);//c++ 코드용 함수
public:
	//TSubclassOf : 지정한 클래스와 클래스를 상속한 모든 클래스를 지정 가능하다.
	//  UUserWidget 클래스와 이 클래스를 상속한 모든 클래스를 지정 가능하다는 뜻
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUserWidget> HudWidgetClass;

	//생성된 위젯을 저장하기 위한 변수
	UPROPERTY(BlueprintReadWrite)
	UUserWidget* HudWidget;


	FTimerHandle th_BindMyPlayerState; // 타이머 추가

};
