#include "Public/DndBaseCharacter.h"
#include "Dnd.h"


ADndBaseCharacter::ADndBaseCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ADndBaseCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void ADndBaseCharacter::Tick(float deltaTime)
{
    Super::Tick(deltaTime);
    Move();
}

void ADndBaseCharacter::Move()
{
    APlayerController* controller = Cast<APlayerController>(GetController());

    float locationX;
    float locationY;
    controller->GetMousePosition(locationX, locationY);

    FVector2D size =  GEngine->GameViewport->Viewport->GetSizeXY();

    float sizeX = size.X;
    float sizeY = size.Y;

    float ratioX = locationX / sizeX;
    float ratioY = locationY / sizeY;

    // not quite right because I think X is forward to start with
    float rightMovement = 0.0f;
    if (ratioX <= .1 || ratioX >= .9)
    {
        rightMovement = 1.0f - ratioX;
    }

    float forwardMovement = 0.0f;
    if (ratioY <= 0.1f || ratioY >= 0.9f)
    {
        forwardMovement = 1.0f - ratioY;
    }

    FVector direction(rightMovement, forwardMovement, 0.0f);

    GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, direction.ToString());

    AddMovementInput(direction, 0.25f);
}

void ADndBaseCharacter::SetupPlayerInputComponent(UInputComponent* playerInputComponent)
{
    Super::SetupPlayerInputComponent(playerInputComponent);
}
