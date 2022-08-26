// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerFloorButton.h"

ATriggerFloorButton::ATriggerFloorButton()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	
	OnActorBeginOverlap.AddDynamic(this, &ATriggerFloorButton::dispRotation);
	

	// ...
}


// Called when the game starts
void ATriggerFloorButton::BeginPlay()
{
	Super::BeginPlay();
	TargetDoor = Cast<UArbitraryDoor>(TargetDoorActor->GetComponentByClass(UArbitraryDoor::StaticClass()));
	// ...

}
void ATriggerFloorButton::dispRotation(class AActor* OverlappedActor, class AActor* OtherActor) {
	
	if (OtherActor == this) return;

	TargetDoor->ReceiveRotation(DispatchRotation);
	TargetDoor->ActivateRotation();

}

