// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class LARPSE_API FindNearestEntity
{
private:
	FVector location;
	int FindDist(FVector loc1, FVector loc2);
public:
	FindNearestEntity(FVector loc);
	~FindNearestEntity();

};
