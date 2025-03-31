#include "Game.hpp"
#include "BlackJack.hpp"
#include "GlobalConstants.hpp"
#include "MainMenu.hpp"
#include "OptionsMenu.hpp"
#include "flags.hpp"
#include <iostream>
#include <raylib.h>
#include <vector>

OptionsMenu Options_Menu;
MainMenu Main_Menu;
BlackJack BlackJack;

Game::Game() : BlackJackButton(BlackJackText, BlackJackPos, BLACK) {
  GlobalConstants::sel_btn_arr.push_back(&BlackJackButton);
}

Game::~Game() {
  std::cout << "Game Destroyed\n";
}

void Game::Loop() {
  Update();
  Draw();
}

void Game::Draw() {
  switch (Flags::ACTIVE_FLAG) {
    case Flags::MAIN_MENU     : Main_Menu.Loop(); break;
    case Flags::OPTIONS_MENU  : Options_Menu.Loop(); break;
    case Flags::GAME_SELECTOR : DrawGameSelectors(); break;
    case Flags::GAME_BLACKJACK: BlackJack.Loop(); break;
  }
}

void Game::DrawGameSelectors() {
  BeginDrawing();
  ClearBackground(BLACK);
  for (Button* btn : GlobalConstants::sel_btn_arr) {
    btn->Draw();
  }
  EndDrawing();
}

void Game::DrawBlackJack() {
  BeginDrawing();
  ClearBackground(BLUE);
  EndDrawing();
}

void Game::Update() {
  if (IsKeyPressed(KEY_ENTER)) {
    Flags::SetFlags(Flags::MAIN_MENU);
  }
  if (BlackJackButton.isClicked()) {
    BlackJack.ReInit();
    Flags::ACTIVE_FLAG = Flags::GAME_BLACKJACK;
    std::cout << "Button Clicked\n";
  }
}
