// Fill out your copyright notice in the Description page of Project Settings.


#include "RigidBodyComponent.h"

URigidBodyComponent::URigidBodyComponent(const FVector& Position)
{
	this->Position = Position;
	Velocity = FVector::ZeroVector;
	Acceleration = FVector::ZeroVector;
}

void URigidBodyComponent::ApplyForce(const FVector& Force)
{
	Acceleration = Force * MassInv;
}

void URigidBodyComponent::Integrate(float Dtime)
{
	Position += Velocity * Dtime;
	Velocity += Acceleration * Dtime;
	Acceleration = FVector::ZeroVector;
}
