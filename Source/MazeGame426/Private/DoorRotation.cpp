// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorRotation.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/TriggerBox.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UDoorRotation::UDoorRotation()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorRotation::BeginPlay()
{
	Super::BeginPlay();
	startRotation = GetOwner()->GetActorRotation();
	finalRotation = GetOwner()->GetActorRotation() + desiredRotation;
	currentTime = 0.0f;
	// ...
	
}


// Called every frame
void UDoorRotation::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (currentTime < timeToRotate) {
		if (TriggerBox && GetWorld() && GetWorld()->GetFirstLocalPlayerFromController()) {
			APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
			if (PlayerPawn && TriggerBox->IsOverlappingActor(PlayerPawn)) {
				currentTime += DeltaTime;
				const float TimeRatio = FMath::Clamp(currentTime / timeToRotate, 0.0f, 1.0f);
				const float RotationAlpha = OpenCurve.GetRichCurveConst()->Eval(TimeRatio);
				const FRotator currentRotation = FMath::Lerp(startRotation, finalRotation, RotationAlpha);
				GetOwner()->SetActorRotation(currentRotation);
			}
		}
	}
	// ...
}

