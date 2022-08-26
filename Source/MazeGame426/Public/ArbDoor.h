// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ArbDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAZEGAME426_API UArbDoor : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UArbDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	//UPROPERTY(EditAnywhere)
		//UArbitraryDoor* TargetDoor;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
