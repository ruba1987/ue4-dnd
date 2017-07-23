#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DndPawn.generated.h"

UCLASS()
class DND_API ADndPawn : public APawn
{
    GENERATED_BODY()

public:
    ADndPawn();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
