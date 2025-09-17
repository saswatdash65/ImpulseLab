// Fill out your copyright notice in the Description page of Project Settings.


#include "AABBComponent.h"

UAABBComponent::UAABBComponent()
{
	FVector centre = FVector::ZeroVector;
	Min = centre - FVector(50.0f);
	Max = centre + FVector(50.0f);
}

void UAABBComponent::ComputeAABB(const FVector& Centre, float Extent)
{
	Min = Centre - FVector(Extent);
	Max = Centre + FVector(Extent);
}

void UAABBComponent::ComputeAABB(const FVector& Min, const FVector& Max)
{
	this->Min = Min;
	this->Max = Max;
}

void UAABBComponent::ComputeAABB(const FBox& Box)
{
	Min = Box.Min;
	Max = Box.Max;
}

bool UAABBComponent::Intersects(const UAABBComponent* Other) const
{
	return (Min.X <= Other->Max.X && Max.X >= Other->Min.X) &&
			(Min.Y <= Other->Max.Y && Max.Y >= Other->Min.Y) &&
			(Min.Z <= Other->Max.Z && Max.Z >= Other->Min.Z);
}

bool UAABBComponent::Intersects(const FBox& Box) const
{
	return (Min.X <= Box.Max.X && Max.X >= Box.Min.X) &&
			(Min.Y <= Box.Max.Y && Max.Y >= Box.Min.Y) &&
			(Min.Z <= Box.Max.Z && Max.Z >= Box.Min.Z);
}
