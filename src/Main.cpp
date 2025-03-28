#include "Game.hpp"
#include "GlobalConstants.hpp"
#include "MainMenu.hpp"
#include "OptionsMenu.hpp"
#include "flags.hpp"
#include <raylib.h>

Game game;

int main() {
    InitWindow(GlobalConstants::ScreenSize.x, GlobalConstants::ScreenSize.y,
               GlobalConstants::ScreenTitle);
    SetTargetFPS(60);

    game.TestCards();

    while (!WindowShouldClose()) {
        game.Loop();
    }

    CloseWindow();
    return 0;
}
