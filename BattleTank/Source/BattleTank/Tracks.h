// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Tracks.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTracks : public UStaticMeshComponent
{
	GENERATED_BODY()
	

public:
	//Sets a throttle between -1 and +1
	//Sets a throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
};
