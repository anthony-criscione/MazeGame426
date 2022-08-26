// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Curves/CurveFloat.h"
#include "ArbitraryDoor.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAZEGAME426_API UArbitraryDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UArbitraryDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		FRotator desiredRotation = FRotator::ZeroRotator;
	FRotator defaultRotation = FRotator::ZeroRotator;
	FRotator startRotation = FRotator::ZeroRotator;
	FRotator finalRotation = FRotator::ZeroRotator;
	

	UPROPERTY(EditAnywhere)
		FRotator seeRotation = FRotator::ZeroRotator;


	UPROPERTY(EditAnywhere)
		float timeToRotate = 1.0f;
	float currentTime = 0.0f;

	bool isRotating = false;


	UPROPERTY(EditAnywhere)
		FRuntimeFloatCurve OpenCurve;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool ReceiveRotation(FRotator goalRot, float newTime = -1.0f, bool swappable = true, bool resetDef = false);
	bool ActivateRotation();
	bool SwapDoor(bool toDefault = false);
	bool SwapDoorInterrupt();
	bool IsAnimating();
};
