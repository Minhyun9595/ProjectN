// Fill out your copyright notice in the Description page of Project Settings.


#include "CGameManager.h"

// Sets default values for this component's properties
UCGameManager::UCGameManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCGameManager::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("게임매니저 BeginPlay"));

	// UObject* SpawnActor = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Script/Engine.Blueprint'/Game/Assets/BP_Cube.BP_Cube'")));

	// UBlueprint* GeneratedBP = Cast<UBlueprint>(SpawnActor);

	// if (!SpawnActor)
	// {
	// 	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("CANT FIND OBJECT TO SPAWN")));
	// 	return;
	// }

	// UClass* SpawnClass = SpawnActor->StaticClass();
	// if (SpawnClass == NULL)
	// {
	// 	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("CLASS == NULL")));
	// 	return;
	// }

	// UWorld* World = GetWorld();
	// FActorSpawnParameters SpawnParams;
	// SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	// World->SpawnActor<AActor>(GeneratedBP->GeneratedClass, FVector(0.0f, 0.0f, 0.0f), FRotator::ZeroRotator, SpawnParams);

	UWorld* world = GetWorld();

	if (world)
	{
		for (int i_x = 0; i_x < cellX; ++i_x)
		{
			for (int j_y = 0; j_y < cellY; ++j_y)
			{
				FActorSpawnParameters SpawnParams;
				SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
				
				FVector vec = FVector(i_x * 100, j_y * 100, 0);
				world->SpawnActor<AActor>(cubeBluePrint, vec, FRotator::ZeroRotator, SpawnParams);
			}
		}
	}
	
}


// Called every frame
void UCGameManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// int32 Random=FMath::RandRange(1, 20);
	
	// if (Random == 1 && cubeBluePrint)
	// {
	// 	UE_LOG(LogTemp, Error, TEXT("Random %d"), Random);
	// 	UWorld* world = GetWorld();
	// 	if (world)
	// 	{
	// 		UE_LOG(LogTemp, Log, TEXT("SpawnAmmo"));
	// 		FActorSpawnParameters SpawnParams;
	// 		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
			
	// 		world->SpawnActor<AActor>(cubeBluePrint, FVector(0.0f, 0.0f, 0.0f), FRotator::ZeroRotator, SpawnParams);
	// 	}
	// }
}

