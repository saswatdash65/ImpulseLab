// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RigidBodyComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class IMPULSELAB_API URigidBodyComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	URigidBodyComponent(const FObjectInitializer& ObjectInitializer);
	explicit URigidBodyComponent(const FVector& Position);

	FVector Position;
	FVector Velocity;
	FVector Acceleration;
	float Mass = 1.0f;
	float MassInv = 1.0f; // Inverse mass: 1/mass

	void ApplyForce(const FVector& Force);
	void Integrate(float Dtime);
};
