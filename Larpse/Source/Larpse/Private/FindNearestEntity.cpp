// Fill out your copyright notice in the Description page of Project Settings.

#include "FindNearestEntity.h"
#include <math.h>

FindNearestEntity::FindNearestEntity(FVector loc)
{
	location = loc;
}

FindNearestEntity::~FindNearestEntity()
{
}

int FindNearestEntity::FindDist(FVector loc1, FVector loc2)
{

	int squaredX, squaredY, squaredZ;
	squaredX = pow((loc2.X - loc1.X), 2);
	squaredY = pow((loc2.Y - loc1.Y), 2);
	squaredZ = pow((loc2.Z - loc1.Z), 2);
	return pow((squaredX + squaredY + squaredZ), .5);

}
