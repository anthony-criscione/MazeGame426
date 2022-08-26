// Fill out your copyright notice in the Description page of Project Settings.


#include "ArbitraryDoor.h"

// Sets default values for this component's properties
UArbitraryDoor::UArbitraryDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UArbitraryDoor::BeginPlay()
{
	Super::BeginPlay();
	startRotation = GetOwner()->GetActorRotation();
	defaultRotation = GetOwner()->GetActorRotation();
	finalRotation = GetOwner()->GetActorRotation() + desiredRotation;
	currentTime = 0.0f;
	isRotating = false;
	// ...
	
}


// Called every frame
void UArbitraryDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!isRotating) return;

	if (currentTime < timeToRotate) {
		/*if (TriggerBox && GetWorld() && GetWorld()->GetFirstLocalPlayerFromController()) {
			APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
			if (PlayerPawn && TriggerBox->IsOverlappingActor(PlayerPawn)) {*/
				currentTime += DeltaTime;
				const float TimeRatio = FMath::Clamp(currentTime / timeToRotate, 0.0f, 1.0f);
				const float RotationAlpha = OpenCurve.GetRichCurveConst()->Eval(TimeRatio);
				const FRotator currentRotation = FMath::Lerp(startRotation, finalRotation, RotationAlpha);
				GetOwner()->SetActorRotation(currentRotation);
				if (TimeRatio >= 1.0f) {
					isRotating = false;
					currentTime = 0.0f;
				}
		/* }
			}
		}*/
	}

	// ...
}

bool UArbitraryDoor::ActivateRotation() {
	if (isRotating) return false;
	isRotating = true;
	return true;
}

bool UArbitraryDoor::ReceiveRotation(FRotator goalRot, float newTime, bool swappable, bool resetDef) {
	if (isRotating) return false;
	if (swappable && finalRotation == goalRot) SwapDoor();
	else {
		finalRotation = goalRot;
		startRotation = GetOwner()->GetActorRotation();
	}
	if (newTime > 0.0f) timeToRotate = newTime;
	if (resetDef) defaultRotation = GetOwner()->GetActorRotation();
	return true;
}

bool UArbitraryDoor::SwapDoor(bool toDefault) {
	if (isRotating) return false;
	FRotator temp = finalRotation;
	if (toDefault) finalRotation = defaultRotation;
	else finalRotation = startRotation;
	startRotation = temp;
	return true;
}

bool UArbitraryDoor::SwapDoorInterrupt() {
	if (isRotating) currentTime = timeToRotate - currentTime;
	FRotator temp = finalRotation;
	finalRotation = startRotation;
	startRotation = temp;
	return true;
}

bool UArbitraryDoor::IsAnimating() {
	return isRotating;
}