// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EntityLocater.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LARPSE_API UEntityLocater : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEntityLocater();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	FVector parentLocation;
	AActor* ParentActor;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "General")
	int FindDist(FVector loc1, FVector loc2);

	UFUNCTION(BlueprintCallable, CallInEditor, Category = "General")
	AActor* FindNearestActor(TArray<AActor*> actors);
};
