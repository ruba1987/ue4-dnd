#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DndBaseCharacter.generated.h"

UCLASS()
class DND_API ADndBaseCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ADndBaseCharacter();

    virtual void Tick(float deltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* playerInputComponent) override;

protected:
    virtual void BeginPlay() override;

    void Move();
};
