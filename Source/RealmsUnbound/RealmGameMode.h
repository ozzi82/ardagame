#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RealmGameMode.generated.h"

UCLASS()
class REALMSUNBOUND_API ARealmGameMode : public AGameModeBase
{
    GENERATED_BODY()
public:
    ARealmGameMode();
    virtual void StartPlay() override;
};
