#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RealmCharacter.generated.h"

UCLASS()
class REALMSUNBOUND_API ARealmCharacter : public ACharacter
{
    GENERATED_BODY()
public:
    ARealmCharacter();
    virtual void SetupPlayerInputComponent(UInputComponent* Input) override;
private:
    void Forward(float Value);
    void Right(float Value);
    void Sprint();
    void Walk();
    UPROPERTY(VisibleAnywhere) class USpringArmComponent* CameraBoom;
    UPROPERTY(VisibleAnywhere) class UCameraComponent* Camera;
    UPROPERTY(VisibleAnywhere) class UStaticMeshComponent* Body;
};
