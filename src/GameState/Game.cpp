#include "Game.hpp"
#include "GlobalConstants.hpp"
#include "flags.hpp"
#include <iostream>
#include <raylib.h>

Game::Game() : BlackJackButton(BlackJackText, BlackJackPos, BLACK) {
    GlobalConstants::sel_btn_arr.push_back(&BlackJackButton);
}

Game::~Game() {}

void Game::Loop() {
    Update();
    Draw();
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BlackJackButton.Draw();
    EndDrawing();
}

void Game::DrawGameSelectors() {
    for (Button* btn : GlobalConstants::sel_btn_arr) {
        btn->Draw();
    }
}

void Game::Update() {
    if (IsKeyPressed(KEY_ENTER)) {
        Flags::SetFlags(3);
    }
    if (BlackJackButton.isClicked()) {
        // Enter Black Jack
        std::cout << "Black Jack Clicked\n";
    }
}
