#include "DndPawn.h"

ADndPawn::ADndPawn()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ADndPawn::BeginPlay()
{
    Super::BeginPlay();
}

void ADndPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ADndPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}
