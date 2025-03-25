#include "Game.hpp"
#include "GlobalConstants.hpp"
#include "MainMenu.hpp"
#include "OptionsMenu.hpp"
#include "flags.hpp"
#include <raylib.h>

Game game;
MainMenu MainMenu;
OptionsMenu optionsMenu;

int main() {
    InitWindow(GlobalConstants::ScreenSize.x, GlobalConstants::ScreenSize.y,
               GlobalConstants::ScreenTitle);
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        while (Flags::ActiveMode::inMainMenu && !WindowShouldClose()) {
            MainMenu.Loop();
        }
        while (Flags::ActiveMode::inOptionsMenu && !WindowShouldClose()) {
            optionsMenu.Loop();
        }
        while (Flags::ActiveMode::inGame && !WindowShouldClose()) {
            game.Loop();
        }
    }

    CloseWindow();
    return 0;
}
