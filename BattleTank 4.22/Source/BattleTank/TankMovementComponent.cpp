// Fill out your copyright notice in the Description page of Project Settings.


#include "Tracks.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::IntendMoveForward(float Throw) 
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f."), Throw);

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::Initialise(UTracks* LeftTrackToSet, UTracks* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
	//TODO Prevent Double speed from double control use.
}
