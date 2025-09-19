// Fill out your copyright notice in the Description page of Project Settings.


#include "ConstraintSolver.h"

void UConstraintSolver::SolveDistanceConstraint(URigidBodyComponent* A, URigidBodyComponent* B, float RestLength)
{
	FVector Delta = B->Position - A->Position;
	float CurrentLength = Delta.Size();
	float Error = CurrentLength - RestLength;

	FVector Correction = (Error / CurrentLength) * Delta * 0.5f;
	A->Position += Correction;
	B->Position -= Correction;
}
