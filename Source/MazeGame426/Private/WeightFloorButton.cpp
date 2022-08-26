// Fill out your copyright notice in the Description page of Project Settings.


#include "WeightFloorButton.h"

AWeightFloorButton::AWeightFloorButton()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.

	OnActorBeginOverlap.AddDynamic(this, &AWeightFloorButton::dispRotation);
	OnActorEndOverlap.AddDynamic(this, &AWeightFloorButton::leaveRotation);

	// ...
}


// Called when the game starts
void AWeightFloorButton::BeginPlay()
{
	Super::BeginPlay();
	TargetDoor = Cast<UArbitraryDoor>(TargetDoorActor->GetComponentByClass(UArbitraryDoor::StaticClass()));
	// ...

}

void AWeightFloorButton::dispRotation(class AActor* OverlappedActor, class AActor* OtherActor) {

	if (OtherActor == this) return;

	if (TargetDoor->IsAnimating()) {
		TargetDoor->SwapDoorInterrupt();
		return;
	}
	TargetDoor->ReceiveRotation(DispatchRotation, -1.0f, false, false);
	TargetDoor->ActivateRotation();

}

void AWeightFloorButton::leaveRotation(class AActor* OverlappedActor, class AActor* OtherActor) {

	if (OtherActor == this) return;

	if (TargetDoor->IsAnimating()) {
		TargetDoor->SwapDoorInterrupt();
		return;
	}
	TargetDoor->SwapDoor();
	TargetDoor->ActivateRotation();

}