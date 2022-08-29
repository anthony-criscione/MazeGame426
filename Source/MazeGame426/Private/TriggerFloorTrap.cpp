// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerFloorTrap.h"

ATriggerFloorTrap::ATriggerFloorTrap()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.

	OnActorBeginOverlap.AddDynamic(this, &ATriggerFloorTrap::dispRotation);
	beenTripped = false;

	// ...
}


// Called when the game starts
void ATriggerFloorTrap::BeginPlay()
{
	Super::BeginPlay();
	TargetDoor = Cast<UArbitraryDoor>(TargetDoorActor->GetComponentByClass(UArbitraryDoor::StaticClass()));
	beenTripped = false;
	// ...

}
void ATriggerFloorTrap::dispRotation(class AActor* OverlappedActor, class AActor* OtherActor) {

	if (OtherActor == this) return;
	if (beenTripped) return;
	beenTripped = TargetDoor->ReceiveRotation(DispatchRotation);
	TargetDoor->ActivateRotation();

}