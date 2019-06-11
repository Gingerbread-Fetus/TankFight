// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //Must be the last include

class UTankAimingComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:

	void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	

private:
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;

	void SetPawn(APawn* InPawn);

	UFUNCTION()
	void OnPosessedTankDeath();
	
	//Moves barrel towards the crosshair
	void AimTowardCrosshair();

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333;
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);
};
