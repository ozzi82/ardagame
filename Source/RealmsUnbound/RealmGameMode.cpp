#include "RealmGameMode.h"
#include "RealmCharacter.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/DirectionalLight.h"
#include "Engine/SkyLight.h"
#include "Components/StaticMeshComponent.h"
#include "Components/DirectionalLightComponent.h"
#include "Engine/World.h"
#include "UObject/ConstructorHelpers.h"

ARealmGameMode::ARealmGameMode() { DefaultPawnClass = ARealmCharacter::StaticClass(); }
void ARealmGameMode::StartPlay()
{
    // Generate collision geometry before the default pawn begins simulating.
    UWorld* World = GetWorld();
    UStaticMesh* Cube = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube"));
    auto Block = [World, Cube](FVector Position, FVector Scale)
    {
        AStaticMeshActor* Actor = World->SpawnActor<AStaticMeshActor>(Position, FRotator::ZeroRotator);
        if (Actor && Cube)
        {
            Actor->GetStaticMeshComponent()->SetStaticMesh(Cube);
            Actor->SetActorScale3D(Scale);
        }
    };
    Block(FVector(0, 0, -100), FVector(200, 200, 1));
    // Central avenue and village buildings, with room to walk between them.
    Block(FVector(0, 0, -44), FVector(12, 170, 0.1f));
    for (int32 Row = -3; Row <= 3; ++Row)
    {
        for (int32 Side : {-1, 1})
        {
            const float X = Side * 1800.0f;
            const float Y = Row * 1800.0f;
            Block(FVector(X, Y, 200), FVector(9, 11, 5));
            Block(FVector(X, Y, 480), FVector(10, 12, 0.6f));
        }
    }
    // Castle walls and four towers at the northern end of the avenue.
    Block(FVector(0, 7600, 500), FVector(45, 2, 11));
    Block(FVector(-2200, 6500, 500), FVector(2, 24, 11));
    Block(FVector(2200, 6500, 500), FVector(2, 24, 11));
    for (int32 Side : {-1, 1})
        for (float Y : {5400.0f, 7600.0f})
            Block(FVector(Side * 2200, Y, 750), FVector(6, 6, 16));
    ADirectionalLight* Sun = World->SpawnActor<ADirectionalLight>(FVector(0, 0, 2000), FRotator(-45, -30, 0));
    if (Sun) Sun->GetLightComponent()->SetIntensity(4.0f);
    World->SpawnActor<ASkyLight>();
    Super::StartPlay();
}
