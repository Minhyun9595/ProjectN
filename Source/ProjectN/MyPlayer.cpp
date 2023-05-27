// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Pawn.h"

// Sets default values for this component's properties
UMyPlayer::UMyPlayer()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyPlayer::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyPlayer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMyPlayer::OnClickEvent(APlayerController* controller)
{
    // 마우스 좌표 가져오기
	//FVector2D MousePosition;
    //if (GEngine && GEngine->GameViewport)
    //{
    //    GEngine->GameViewport->GetMousePosition(MousePosition);
    //}

    FVector2D ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
    FVector2D ScreenCenter = ViewportSize / 2.0f;
    
    
    FVector WorldLocation, WorldDirection;

    // 마우스 위치를 3D 월드 공간으로 변환합니다.
    //controller->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);

    // 스크린 중앙 위치를 3D 월드 공간으로 변환.
    controller->DeprojectScreenPositionToWorld(ScreenCenter.X, ScreenCenter.Y, WorldLocation, WorldDirection);

    // 레이캐스트를 수행하여 액터를 찾습니다.
    FHitResult HitResult;
    GetWorld()->LineTraceSingleByChannel(HitResult, WorldLocation, WorldLocation + WorldDirection * 1000, ECC_Visibility);

    // 레이캐스트로 충돌한 액터를 가져옵니다.
    AActor* HitActor = HitResult.GetActor();

    // 가져온 액터를 사용하면 됩니다.
    if (HitActor)
    {
	    UE_LOG(LogTemp, Warning, TEXT("찾은 객체 %s"), *(HitActor->GetName()));

        // AActor에서 UStaticMeshComponent를 찾습니다.
        UStaticMeshComponent* StaticMeshComponent = HitActor->FindComponentByClass<UStaticMeshComponent>();
        
        //StaticMeshComponent->SetRenderCustomDepth(true);
        StaticMeshComponent->SetMaterial(0, MyMaterial);
    }

    

}
