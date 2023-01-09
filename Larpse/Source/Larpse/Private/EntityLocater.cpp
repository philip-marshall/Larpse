// Fill out your copyright notice in the Description page of Project Settings.


#include "EntityLocater.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UEntityLocater::UEntityLocater()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEntityLocater::BeginPlay()
{
	Super::BeginPlay();
	ParentActor = GetOwner();

	if (ParentActor)
	{
		parentLocation = ParentActor->GetActorLocation();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get parent actor for EntityLocater. Setting default location to 0"));
		parentLocation = FVector(0, 0, 0);
	}
}


// Called every frame
void UEntityLocater::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	parentLocation = GetOwner()->GetActorLocation();
	// ...
}


int UEntityLocater::FindDist(FVector loc1, FVector loc2)
{
	int squaredX, squaredY, squaredZ;
	squaredX = pow((loc2.X - loc1.X), 2);
	squaredY = pow((loc2.Y - loc1.Y), 2);
	squaredZ = pow((loc2.Z - loc1.Z), 2);
	return pow((squaredX + squaredY + squaredZ), .5);

	//UGameplayStatics::GetAllActorsOfClass
}

AActor* UEntityLocater::FindNearestActor(TArray<AActor*> actors)
{
	float tempDist = 9999999999999999999;
	AActor* tempActor = nullptr;
	int size = actors.Num();
	for (int i = 0; i < size - 1; i++)
	{
		if (FindDist(parentLocation, actors[i]->GetActorLocation()) < tempDist)
		{
			tempDist = FindDist(parentLocation, actors[i]->GetActorLocation());
			tempActor = actors[i];
		}
	}

	return tempActor;
}

