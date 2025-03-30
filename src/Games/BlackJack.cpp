#include "BlackJack.hpp"
#include "Deck.hpp"
#include "GlobalConstants.hpp"
#include "flags.hpp"
#include "raylib.h"
#include <iostream>

BlackJack::BlackJack() : deck(GetNumDecks()) {
  deck.ShuffleDeck();
  DealCards(0);
  DealCards(1);
}

void BlackJack::Loop() {
  Update();
  Draw();
}

void BlackJack::Draw() {
  BeginDrawing();
  ClearBackground(BLUE);
  DrawPlayerHands();
  EndDrawing();
}

void BlackJack::Update() {
  if (GameFlag == Flags::StartPlayerTurn || GameFlag == Flags::WaitForInput) {
    PlayerTurn();
  }
  if (GameFlag == Flags::DealerMove) {
    DealerTurn();
  }
}

void BlackJack::DrawPlayerHands() {
  float Offset = 0.9;

  for (Card card : player) {
    float textPosY = GlobalConstants::ScreenSize.y * Offset;
    float textPosX =
        GlobalConstants::ScreenSize.x / 2.0f -
        (MeasureTextEx(GetFontDefault(), card.GetCardName().c_str(), GlobalConstants::FontSize, 1)
             .x) /
            2.0f;
    DrawTextEx(GetFontDefault(), card.GetCardName().c_str(), {textPosX, textPosY},
               GlobalConstants::FontSize, 1, WHITE);
    Offset -= 0.06;
  }
  // std::cout << player.size() << "\n";
}

void BlackJack::DealerTurn() {
  DealerHandValue = 0;
  for (Card card : dealer) {
    DealerHandValue += card.GetCardValue();
  }

  while (DealerHandValue < 16) {
    Hit(1);
    DealerHandValue += dealer.back().GetCardValue();
  }

  Bust();

  std::cout << DealerHandValue << "\n";

  GameFlag = Flags::StartPlayerTurn;
}

void BlackJack::Bust() {
  std::cout << "Busted\n";
  Flags::SetFlags(Flags::MAIN_MENU);
}

void BlackJack::PlayerTurn() {
  if (GameFlag == Flags::StartPlayerTurn) {
    std::cout << "Press \"H\" to hit\n";
    std::cout << "Press \"S\" to stand\n";
  }

  int playerChoice;
  switch (GetKeyPressed()) {
    case KEY_S:
      std::cout << "Player stand\n";
      GameFlag = Flags::DealerMove;
      break;
    case KEY_H:
      Hit(0);
      GameFlag = Flags::DealerMove;
      break;
    default: GameFlag = Flags::WaitForInput; break;
  }
}

void BlackJack::Hit(int turn) {
  switch (turn) {
    case 0:
      player.push_back(deck.DealCard());
      std::cout << player.back().GetCardName() << "\n";
      break;
    case 1:
      dealer.push_back(deck.DealCard());
      std::cout << dealer.back().GetCardName() << "\n";
      break;
  }
}

// Deal Cards To player and dealer
void BlackJack::DealCards(int turn) {
  switch (turn) {
    case 0:
      for (int i = 0; i < 2; i++) {
        player.push_back(deck.DealCard());
        // std::cout << deck.GetDeck().back().GetCardName() << "\n";
      }
      for (Card card : player) {
        std::cout << card.GetCardName() << "\n";
      }
      break;
    case 1:
      for (int i = 0; i < 2; i++) {
        dealer.push_back(deck.DealCard());
        // std::cout << deck.GetDeck().back().GetCardName() << "\n";
      }
      for (Card card : dealer) {
        std::cout << card.GetCardName() << "\n";
      }
      break;
  }
}

int BlackJack::GetNumDecks() {
  std::cout << "Enter Number of Decks: ";
  std::cin >> NumDecks;

  return NumDecks;
}
