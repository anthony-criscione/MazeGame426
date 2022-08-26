// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ArbitraryDoor.h"
#include "ToggleDoorButton.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAZEGAME426_API UToggleDoorButton : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UToggleDoorButton();

protected:
	// Called when the game starts
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
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
