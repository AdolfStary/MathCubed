// Fill out your copyright notice in the Description page of Project Settings.


#include "TetrisPlayerController.h"


ATetrisPlayerController::ATetrisPlayerController() {
	
}

void ATetrisPlayerController::SetupInputComponent()
{

	Super::SetupInputComponent();


	EnableInput(this);

	InputComponent->BindAxis("MoveHorizontal", this, &ATetrisPlayerController::MoveHorizontal);
	InputComponent->BindAxis("DropDown", this, &ATetrisPlayerController::DropDown);
	InputComponent->BindAction("StartGame", IE_Pressed, this, &ATetrisPlayerController::StartGame);
}

void ATetrisPlayerController::BeginPlay()
{
	
	myGameMode = Cast<AMathTetrisGameModeBase>(GetWorld()->GetAuthGameMode());


}


void ATetrisPlayerController::StartGame()
{
	if (myGameMode) {
		if (myGameMode->newGame == true) {
			myGameMode->StartGame();
		}
	}
	

}


void ATetrisPlayerController::MoveHorizontal(float AxisValue)
{
	
	auto theNumberFalling = Cast<ANumberFalling>(GetPawn());
	
	if (theNumberFalling) {

		theNumberFalling->MoveHorizontal(AxisValue);

	}
}

void ATetrisPlayerController::DropDown(float AxisValue)
{

	auto theNumberFalling = Cast<ANumberFalling>(GetPawn());

	if (theNumberFalling) {

		theNumberFalling->DropDown(AxisValue);

	}
	
}


