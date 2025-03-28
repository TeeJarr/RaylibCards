#include "Game.hpp"
#include "Card.hpp"
#include "GlobalConstants.hpp"
#include "MainMenu.hpp"
#include "OptionsMenu.hpp"
#include "flags.hpp"
#include <iostream>
#include <raylib.h>
#include <vector>

OptionsMenu Options_Menu;
MainMenu Main_Menu;

Game::Game() : BlackJackButton(BlackJackText, BlackJackPos, BLACK) {
    GlobalConstants::sel_btn_arr.push_back(&BlackJackButton);
}

Game::~Game() {}

void Game::Loop() {
    Update();
    Draw();
}

void Game::Draw() {
    switch (Flags::ActiveMode::ACTIVE_FLAG) {
    case Flags::MAIN_MENU:
        Main_Menu.Loop();
        break;
    case Flags::OPTIONS_MENU:
        Options_Menu.Loop();
        break;
    case Flags::GAME_SELECTOR:
        DrawGameSelectors();
        break;
    case Flags::GAME_BLACKJACK:
        DrawBlackJack();
        break;
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
        Flags::ActiveMode::ACTIVE_FLAG = Flags::GAME_BLACKJACK;
        std::cout << "Button Clicked\n";
    }
}

void Game::TestCards() {
    std::vector<Card> card_arr;
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            Card newCard(i, j, 0);
            card_arr.push_back(newCard);
        }
    }
    for (int val = 0; val < 3; val++) {
        for (int suit = 0; suit < 4; suit++) {
            Card newCard(10, suit, val);
            card_arr.push_back(newCard);
        }
    }
    for (Card card : card_arr) {
        std::cout << card.GetCardName() << "\n";
    }
}
