// Fill out your copyright notice in the Description page of Project Settings.


#include "ToggleDoorButton.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/TriggerBox.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UToggleDoorButton::UToggleDoorButton()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UToggleDoorButton::BeginPlay()
{
	Super::BeginPlay();
	TargetDoor = Cast<UArbitraryDoor>(TargetDoorActor->GetComponentByClass(UArbitraryDoor::StaticClass()));
	// ...
	
}


// Called every frame
void UToggleDoorButton::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (GetWorld() && GetWorld()->GetFirstLocalPlayerFromController()) {
		APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
		APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
		
		if (PlayerPawn) {
			if ((PlayerController->GetInputAxisValue(TEXT("UseButton"))) > 0.0f) {
				float dist = ((PlayerPawn->GetActorLocation()) - this->GetOwner()->GetActorLocation()).Size();
				/*UE_LOG(LogTemp, Warning, TEXT("Dist between player and button is %f"), dist);
				UE_LOG(LogTemp, Warning, TEXT("The button's forward vec is %s"), *(this->GetOwner()->GetActorForwardVector().ToString()));
				UE_LOG(LogTemp, Warning, TEXT("The player's forward vec is %s"), *(PlayerPawn->GetActorForwardVector().ToString()));*/
				if (dist < PressDist && FVector::DotProduct(this->GetOwner()->GetActorForwardVector(), PlayerPawn->GetActorForwardVector()) < 0.0f) {
				
					TargetDoor->ReceiveRotation(DispatchRotation);
					TargetDoor->ActivateRotation();
					
				}
			}
		}
	}


	// ...
}

