// Fill out your copyright notice in the Description page of Project Settings.


#include "Tracks.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::IntendMoveForward(float Throw) 
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw) 
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::Initialise(UTracks* LeftTrackToSet, UTracks* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
	//TODO Prevent Double speed from double control use.
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	//No need to call super since we are replacing a method.

	auto TankName = GetOwner()->GetName();
	auto VelocityAsString = MoveVelocity.ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s vectoring towards %s"), *TankName, *VelocityAsString);
}
