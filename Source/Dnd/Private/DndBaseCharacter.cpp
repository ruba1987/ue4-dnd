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

    float cursorLocationX;
    float cursorLocationY;
    controller->GetMousePosition(cursorLocationX, cursorLocationY);

    FVector2D screenSize =  GEngine->GameViewport->Viewport->GetSizeXY();


	float cursorPositionRatioY = cursorLocationY / screenSize.Y;
    float cursorPositionRatioX = cursorLocationX / screenSize.X;

    float characterYAxisDirection = 0.0f;
	float characterYDirectionMultiplier = 1.0f;
    if (cursorPositionRatioX <= .1)
    {
		// left
		characterYDirectionMultiplier = -1;
		characterYAxisDirection =  1 - cursorPositionRatioX;
    }
	else if (cursorPositionRatioX >= 0.9f)
	{
		// right
        characterYAxisDirection = cursorPositionRatioX;
	}

    float characterXAxisDirection = 0.0f;
	float characterXDirectionMultiplier = 1.0f;
    if (cursorPositionRatioY <= .1)
    {
		// up
		characterXAxisDirection = 1 - cursorPositionRatioY;
    }
	else if (cursorPositionRatioY >= .9)
	{
		// down
		characterXDirectionMultiplier = -1;
        characterXAxisDirection = cursorPositionRatioY;
	}

    FVector direction(characterXAxisDirection * characterXDirectionMultiplier, characterYAxisDirection * characterYDirectionMultiplier, 0.0f);

	// get the length of the 2D unit vector represented by the position ratio, clamp it to avoid sqrt(2) issues, scale it back to [0, 1]
	float speed = (FMath::Clamp(FMath::Sqrt(characterXAxisDirection * characterXAxisDirection + characterYAxisDirection * characterYAxisDirection), 0.0f, 1.0f) - .9) * 10;

    AddMovementInput(direction, speed);
}

void ADndBaseCharacter::SetupPlayerInputComponent(UInputComponent* playerInputComponent)
{
    Super::SetupPlayerInputComponent(playerInputComponent);
}
