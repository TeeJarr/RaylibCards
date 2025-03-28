#include "Game.hpp"
#include "GlobalConstants.hpp"
#include <raylib.h>

Game game;

int main() {
  InitWindow(GlobalConstants::ScreenSize.x, GlobalConstants::ScreenSize.y,
             GlobalConstants::ScreenTitle);
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    game.Loop();
  }

  CloseWindow();
  return 0;
}
