// Fill out your copyright notice in the Description page of Project Settings.


#include "ContactSolver.h"

void UContactSolver::ResolveContact(const FContact& Contact)
{
	URigidBodyComponent* A = Contact.BodyA;
	URigidBodyComponent* B = Contact.BodyB;

	FVector RelativeVelocity = B->Velocity - A->Velocity;
	float VelAlongNormal = FVector::DotProduct(RelativeVelocity, Contact.ContactNormal);
	if (VelAlongNormal > 0.0f) return;

	const float e = Contact.Restitution;
	const float InvMassSum = A->MassInv + B->MassInv;

	const float ImpulseScalar = -(1 + e) * VelAlongNormal / InvMassSum;
	FVector Impulse = ImpulseScalar * Contact.ContactNormal;

	A->Velocity -= Impulse * A->MassInv;
	B->Velocity += Impulse * B->MassInv;

	// Positional correction (to prevent sinking)
	constexpr float Percent = 0.2f; // usually 20% of penetration
	constexpr float Slop = 0.01f;   // small threshold
	float correctionMagnitude = FMath::Max(Contact.PenetrationDepth - Slop, 0.0f) / InvMassSum;
	FVector Correction = Percent * correctionMagnitude * Contact.ContactNormal;

	A->Position -= Correction * A->MassInv;
	B->Position += Correction * B->MassInv;	
}
