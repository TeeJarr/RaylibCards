#include "MainMenu.hpp"
#include "Button.hpp"
#include "GlobalConstants.hpp"
#include "TextFunctions.hpp"
#include "flags.hpp"
#include "raylib.h"
#include <iostream>

MainMenu::MainMenu()
    : StartText("Start"), OptionsText("Options"),
      StartButton(StartText, {GlobalConstants::ScreenSize.x / 2.0f, GlobalConstants::ScreenSize.y / 2.0f}, BLACK),
      OptionsButton(OptionsText, {GlobalConstants::ScreenSize.x / 2.0f, (GlobalConstants::ScreenSize.y / 2.0f) * 1.2f},
                    BLACK) {
  GlobalConstants::title_btn_arr.push_back(&StartButton);
  GlobalConstants::title_btn_arr.push_back(&OptionsButton);
}

MainMenu::~MainMenu() {}

void MainMenu::Loop() {
  Update();
  Draw();
}

void MainMenu::Draw() {
  BeginDrawing();
  ClearBackground(RED);
  DrawTitle();
  DrawButtons();
  EndDrawing();
}

void MainMenu::Update() {
  CheckButtonUpdates();
}

void MainMenu::DrawTitle() {
  float FontSize = 128;
  DrawTextEx(GlobalConstants::MenuFont, GameTitle,
             {GlobalConstants::ScreenSize.x / 2.0f - text::CenterText(GameTitle, FontSize, GlobalConstants::MenuFont).x, 50},
             FontSize, 1, BLACK);
}

void MainMenu::DrawButtons() {
  for (Button* button : GlobalConstants::title_btn_arr) {
    button->Draw();
  }
}

void MainMenu::CheckButtonUpdates() {
  if (StartButton.isClicked()) {
    Flags::SetFlags(Flags::GAME_SELECTOR);
    EndDrawing();
  }
  if (OptionsButton.isClicked()) {
    Flags::SetFlags(Flags::OPTIONS_MENU);
  }
}
