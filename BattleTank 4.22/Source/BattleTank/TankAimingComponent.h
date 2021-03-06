// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"

//Enum for aiming state
UENUM()
enum class EFiringState : uint8 
{
	Reloading,
	Aiming,
	Locked,
	OutOfAmmo
};

//Forward declaration.
class UTankBarrel;
class UTankTurret;
class AProjectile;

//Holds barrel's properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Fire();

	UFUNCTION(BluePrintCallable, Category = "Setup")
	void SetProjectile(TSubclassOf<AProjectile> ProjectileBlueprintToSet);
	
	void AimAt(FVector HitLocation);

	EFiringState GetFiringState() const;

	int32 GetAmmoCount() const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringStatus = EFiringState::Reloading;
			
private:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void MoveBarrelTowards(FVector AimDirection);

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	
	bool IsBarrelMoving();

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	int32 Ammo = 20;
		
	double LastFireTime = 0;

	FVector AimDirection = FVector(0);

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint; //Alternatively you can use TSubclassOf<UDamageType> DamageType;
	
};
