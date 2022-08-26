// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArbitraryDoor.h"
#include "Engine/TriggerBox.h"
#include "TriggerFloorButton.generated.h"

/**
 * 
 */
UCLASS()
class MAZEGAME426_API ATriggerFloorButton : public ATriggerBox
{
	GENERATED_BODY()

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		AActor* TargetDoorActor;
	UPROPERTY(VisibleAnywhere)
		UArbitraryDoor* TargetDoor;
	UPROPERTY(EditAnywhere)
		FRotator DispatchRotation;
	UPROPERTY(EditAnywhere)
		float PressDist;

public:

	// constructor sets default values for this actor's properties
	ATriggerFloorButton();

	// declare overlap begin function
	//UFUNCTION()
		//void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// declare overlap end function
	//UFUNCTION()
		//void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void dispRotation(class AActor* OverlappedActor, class AActor* OtherActor);

};
