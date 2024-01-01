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
	virtual void BeginPlay() override;

public:
	void BindMyPlayerState();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)//�𸮾�� �Լ�.
		void OnUpdateMyHP(float CuerHP, float MaxHP);// Implementation �Լ��� cpp�� �������־����� �̰� �����ϸ� �ȵ�... ���� ���ǰ� �Ǽ� �������
		void OnUpdateMyHP_Implementation(float CuerHP, float MaxHP);//c++ �ڵ�� �Լ�
public:
	//TSubclassOf : ������ Ŭ������ Ŭ������ ����� ��� Ŭ������ ���� �����ϴ�.
	//  UUserWidget Ŭ������ �� Ŭ������ ����� ��� Ŭ������ ���� �����ϴٴ� ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUserWidget> HudWidgetClass;

	//������ ������ �����ϱ� ���� ����
	UPROPERTY(BlueprintReadWrite)
	UUserWidget* HudWidget;


	FTimerHandle th_BindMyPlayerState; // Ÿ�̸� �߰�

};
