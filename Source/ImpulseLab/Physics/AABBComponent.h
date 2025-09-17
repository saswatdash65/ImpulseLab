// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AABBComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class IMPULSELAB_API UAABBComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAABBComponent();

	FVector Min;
	FVector Max;

	void ComputeAABB(const FVector& Centre, float Extent = 50.0f);
	void ComputeAABB(const FVector& Min, const FVector& Max);
	void ComputeAABB(const FBox& Box);

	bool Intersects(const UAABBComponent* Other) const;
	bool Intersects(const FBox& Box) const;
};
