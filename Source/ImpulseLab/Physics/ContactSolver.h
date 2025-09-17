// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RigidBodyComponent.h"
#include "ContactSolver.generated.h"

struct FContact
{
	URigidBodyComponent* BodyA;
	URigidBodyComponent* BodyB;
	FVector ContactPoint;
	FVector ContactNormal;
	float PenetrationDepth;
	float Restitution; // Passed from environment or material
};

/**
 * 
 */
UCLASS()
class IMPULSELAB_API UContactSolver : public UObject
{
	GENERATED_BODY()

public:
	static void ResolveContact(const FContact& Contact);
	
};
