#include "Game.hpp"
#include "GlobalConstants.hpp"
#include <raylib.h>

Game game;

int main() {
  InitWindow(GlobalConstants::ScreenSize.x, GlobalConstants::ScreenSize.y, GlobalConstants::ScreenTitle);
  SetTargetFPS(60);

  GlobalConstants::CardFont = LoadFontEx("../../res/fonts/Roboto-Regular.ttf", 36, 0, 0);
  Image baseSuitImage       = LoadImage("../../res/images/suits.png");
  ImageResize(&baseSuitImage, 135, 45);
  GlobalConstants::SpadeImage = LoadTextureFromImage(baseSuitImage);

  while (!WindowShouldClose()) {
    game.Loop();
  }

  UnloadFont(GlobalConstants::CardFont);

  CloseWindow();
  return 0;
}
