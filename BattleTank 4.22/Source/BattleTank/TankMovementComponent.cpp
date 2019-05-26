// Fill out your copyright notice in the Description page of Project Settings.


#include "Tracks.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::IntendMoveForward(float Throw) 
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw) 
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::Initialise(UTracks* LeftTrackToSet, UTracks* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
	//TODO Prevent Double speed from double control use.
}
