// Fill out your copyright notice in the Description page of Project Settings.


#include "Tracks.h"

UTracks::UTracks()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetNotifyRigidBodyCollision(true);
}

void UTracks::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTracks::OnHit);
}

void UTracks::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Calculate the slippage speed
	auto SlipSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto CorrectionAcceleration = -SlipSpeed / DeltaTime * GetRightVector();
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; //Two tracks.
	TankRoot->AddForce(CorrectionForce);
}

void UTracks::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("I'm hit."));
}

void UTracks::SetThrottle(float Throttle)
{
	auto Name = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f."), *Name, Throttle);

	// TODO clamp throttle value so player can't over-drive
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}