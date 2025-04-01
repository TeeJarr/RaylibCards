#include "OptionsMenu.hpp"
#include "Button.hpp"
#include "GlobalConstants.hpp"
#include "TextFunctions.hpp"
#include "flags.hpp"
#include "raylib.h"

OptionsMenu::OptionsMenu()
    : button1440p(str_1440p, ResButton1440, BLACK), button1080p(str_1080p, ResButton1080, BLACK),
      button720p(str_720p, ResButton720, BLACK) {
  GlobalConstants::opts_btn_arr.push_back(&button1440p);
  GlobalConstants::opts_btn_arr.push_back(&button1080p);
  GlobalConstants::opts_btn_arr.push_back(&button720p);
}

OptionsMenu::~OptionsMenu() {}

void OptionsMenu::Loop() {
  Update();
  Draw();
}

void OptionsMenu::Draw() {
  BeginDrawing();
  ClearBackground(BLUE);
  DrawTitle();
  DrawButtons();
  EndDrawing();
}

void OptionsMenu::Update() {
  UpdateButtons();
  if (IsKeyPressed(KEY_ENTER)) {
    // returns to the main menu
    Flags::SetFlags(3);
  }
}

void OptionsMenu::DrawTitle() {
  float FontSize = 128;
  DrawTextEx(GetFontDefault(), OptionsTitle,
             {(GlobalConstants::ScreenSize.x / 2.0f) - text::CenterText(OptionsTitle, FontSize, GetFontDefault()).x, 50},
             FontSize, 1, BLACK);
}

void OptionsMenu::UpdateButtons() {
  ChangeWindowSize();
}

void OptionsMenu::DrawButtons() {
  // Don't have to manually draw each button when new button is added
  for (Button* button : GlobalConstants::opts_btn_arr) {
    button->Draw();
  }
}

void OptionsMenu::ChangeButtonPos() {
  // makes the variable adapt to the new screen size
  ResButton1080 = {(GlobalConstants::ScreenSize.x / 2.0f), GlobalConstants::ScreenSize.y / 3.0f};
  ResButton1440 = {(GlobalConstants::ScreenSize.x / 2.0f) * 0.8f, GlobalConstants::ScreenSize.y / 3.0f};
  ResButton720  = {(GlobalConstants::ScreenSize.x / 2.0f) * 1.2f, GlobalConstants::ScreenSize.y / 3.0f};

  // changes the size of the buttons
  button1080p.UpdateButtonPos(ResButton1080);
  button720p.UpdateButtonPos(ResButton720);
  button1440p.UpdateButtonPos(ResButton1440);

  // change size of start menu buttons
  GlobalConstants::title_btn_arr[0]->UpdateButtonPos(
      {GlobalConstants::ScreenSize.x / 2.0f, GlobalConstants::ScreenSize.y / 2.0f});
  GlobalConstants::title_btn_arr[1]->UpdateButtonPos(
      {GlobalConstants::ScreenSize.x / 2.0f, GlobalConstants::ScreenSize.y / 2.0f * 1.2f});

  // change size of game control buttons
  GlobalConstants::game_ctrl_arr[0]->UpdateButtonPos(
      {GlobalConstants::ScreenSize.x * 0.9f, GlobalConstants::ScreenSize.y * 0.85f});
  GlobalConstants::game_ctrl_arr[1]->UpdateButtonPos(
      {GlobalConstants::ScreenSize.x * 0.9f, GlobalConstants::ScreenSize.y * 0.93f});
}

void OptionsMenu::ChangeWindowSize() {
  if (button1440p.isClicked()) {
    GlobalConstants::ScreenSize = {2560, 1440};
    GlobalConstants::FontSize   = 72;
    ChangeButtonPos();
  }
  if (button1080p.isClicked()) {
    GlobalConstants::ScreenSize = {1920, 1080};
    GlobalConstants::FontSize   = 56;
    ChangeButtonPos();
  }
  if (button720p.isClicked()) {
    GlobalConstants::ScreenSize = {1280, 720};
    GlobalConstants::FontSize   = 48;
    ChangeButtonPos();
  }
  SetWindowSize(GlobalConstants::ScreenSize.x, GlobalConstants::ScreenSize.y);
  ChangeButtonPos();
}
