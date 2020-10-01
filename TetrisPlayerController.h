// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerState.h"
#include "NumberFalling.h"
#include "MathTetrisGameModeBase.h"
#include "GameFramework/GameModeBase.h"
#include "TetrisPlayerController.generated.h"

/**
 * 
 */
class ANumberFalling;
class AMathTetrisGameModeBase;
UCLASS()
class MATHTETRIS_API ATetrisPlayerController : public APlayerController
{
	GENERATED_BODY()
	


		ATetrisPlayerController();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		AMathTetrisPlayerState* thePlayer;


	UFUNCTION()
		virtual void SetupInputComponent() override;




	void StartGame();
	void MoveHorizontal(float AxisValue);
	void DropDown(float AxisValue);

	AMathTetrisGameModeBase* myGameMode;
	


protected:
	virtual void BeginPlay() override;


};
