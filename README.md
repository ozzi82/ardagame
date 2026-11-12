# Realms Unbound

An Unreal Engine 5.4 C++ starting point for the Realms Unbound design.

## Run locally

1. Install Unreal Engine 5.4 and its supported C++ compiler (Visual Studio 2022 with Game development with C++ on Windows).
2. Right-click `RealmsUnbound.uproject` and generate project files.
3. Build the **Development Editor** target, then open the project.
4. Open a new **Basic** level, set World Settings → GameMode Override to `RealmGameMode` (or None to use the project default), and add a Player Start at `(0, -7000, 150)`.
5. Save the level as `/Game/Maps/Valoria`, set it as both startup and game default map in Project Settings → Maps & Modes, and press Play.

The game mode creates a flat 200 × 200 metre village blockout with collision, an avenue, castle walls and towers, and lighting when play starts. The character is a placeholder cube, not an animated character asset. The engine Entry map is a temporary startup placeholder; create the level above before evaluating gameplay or packaging.

Controls: WASD move, mouse look, Space jump, Left Shift sprint. Click the play viewport to capture the mouse; Shift+F1 releases it.

## Current scope

This is a source scaffold for phase 1, not the finished game. It includes movement, a spring-arm third-person camera, and generated 3D blockout geometry. There are no imported art assets, vehicles, missions, interactions, saves, accounts, or multiplayer yet.

Unreal Engine is not installed in the cloud workspace where these files were prepared. Compilation, editor startup, collision, lighting, and input behavior still require local Unreal validation. No packaged executable is included.

## Next milestones

- Compile and test the prototype in UE5; save a dedicated Valoria level.
- Replace placeholders with a rigged character, terrain, and licensed environment assets.
- Add an interaction interface and the first enterable vehicle.
- Add one complete delivery mission with rewards and local saving.
- Expand Valoria before building the other six lands.

See `Docs/GameDesign.md` for the supplied full vision.
