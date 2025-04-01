#include "Game.hpp"
#include "GlobalConstants.hpp"
#include <iostream>
#include <raylib.h>

Game game;

void LoadFonts();
void LoadResources();
void LoadTextures();

void UnloadFonts();
void UnloadResources();
void UnloadTextures();

int main() {
  InitWindow(GlobalConstants::ScreenSize.x, GlobalConstants::ScreenSize.y, GlobalConstants::ScreenTitle);
  SetTargetFPS(60);

  LoadResources();

  while (!WindowShouldClose()) {
    game.Loop();
  }

  UnloadResources();

  CloseWindow();
  return 0;
}

void LoadResources() {
  LoadFonts();
  LoadTextures();
}

void LoadFonts() {
  GlobalConstants::CardFont   = LoadFontEx("../../res/fonts/Roboto-Regular.ttf", 36, 0, 0);
  GlobalConstants::MenuFont   = LoadFontEx("../../res/fonts/Roboto-Regular.ttf", 128, 0, 0);
  GlobalConstants::ButtonFont = LoadFontEx("../../res/fonts/Roboto-Regular.ttf", 24, 0, 0);
}

void LoadTextures() {
  Image baseSuitImage = LoadImage("../../res/images/suits.png");
  ImageResize(&baseSuitImage, 135, 45);
  GlobalConstants::SpadeImage = LoadTextureFromImage(baseSuitImage);
  UnloadImage(baseSuitImage);
}

void UnloadResources() {
  UnloadFonts();
  UnloadTextures();
  std::cout << "finised unloading\n";
}

void UnloadTextures() {
  UnloadTexture(GlobalConstants::SpadeImage);
  std::cout << "unloaded textures\n";
}

void UnloadFonts() {
  UnloadFont(GlobalConstants::CardFont);
  UnloadFont(GlobalConstants::MenuFont);
  UnloadFont(GlobalConstants::ButtonFont);
  std::cout << "unloaded fonts\n";
}
