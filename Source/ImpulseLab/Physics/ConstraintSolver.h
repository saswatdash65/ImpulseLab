// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RigidBodyComponent.h"
#include "ConstraintSolver.generated.h"

/**
 * 
 */
UCLASS()
class IMPULSELAB_API UConstraintSolver : public UObject
{
	GENERATED_BODY()
public:
	static void SolveDistanceConstraint(URigidBodyComponent* A, URigidBodyComponent* B, float RestLength);
};
