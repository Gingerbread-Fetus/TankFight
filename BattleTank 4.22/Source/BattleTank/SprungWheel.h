// Copyright EmbraceIT Ltd.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "SprungWheel.generated.h"

UCLASS()
class BATTLETANK_API ASprungWheel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASprungWheel();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AddDrivingForce(float ForceMagnitude);
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* Wheel;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* Axle;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPhysicsConstraintComponent* MassWheelConstraint;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPhysicsConstraintComponent* WheelAxleConstraint;

	float TotalForceMagnitudeThisFrame = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void SetUpConstraint();
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	void ApplyForce();
};
