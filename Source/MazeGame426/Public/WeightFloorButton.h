// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "ArbitraryDoor.h"
#include "WeightFloorButton.generated.h"

UCLASS()
class MAZEGAME426_API AWeightFloorButton : public ATriggerBox
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
	AWeightFloorButton();

	// declare overlap begin function
	//UFUNCTION()
		//void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// declare overlap end function
	//UFUNCTION()
		//void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		void dispRotation(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
		void leaveRotation(class AActor* OverlappedActor, class AActor* OtherActor);
	
};
