#include "BlackJack.hpp"
#include "Deck.hpp"
#include "GlobalConstants.hpp"
#include "flags.hpp"
#include "raylib.h"
#include <iostream>

BlackJack::BlackJack() : deck(GetNumDecks()) {
  deck.ShuffleDeck();
}

void BlackJack::ReInit() {
  ClearHands();
  DealCards(Flags::PLAYER);
  DealCards(Flags::DEALER);
}

void BlackJack::ClearHands() {
  player.clear();
  dealer.clear();
}

void BlackJack::Loop() {
  Update();
  Draw();
}

void BlackJack::Draw() {
  BeginDrawing();
  ClearBackground(BLUE);
  DrawPlayerHands();
  DrawDealerHands();
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

void BlackJack::DrawDealerHands() {
  float Offset = 0.1;

  for (Card card : dealer) {
    float textPosY = GlobalConstants::ScreenSize.y * Offset;
    float textPosX =
        GlobalConstants::ScreenSize.x / 2.0f -
        (MeasureTextEx(GetFontDefault(), card.GetCardName().c_str(), GlobalConstants::FontSize, 1)
             .x) /
            2.0f;
    DrawTextEx(GetFontDefault(), card.GetCardName().c_str(), {textPosX, textPosY},
               GlobalConstants::FontSize, 1, WHITE);
    Offset += 0.06;
  }
}

void BlackJack::DealerTurn() {
  DealerHandValue = 0;
  for (Card card : dealer) {
    DealerHandValue += card.GetCardValue();
  }
  while (DealerHandValue < 16) {
    Hit(Flags::DEALER);
    DealerHandValue += dealer.back().GetCardValue();
  }
  if (DealerHandValue > 21 || CheckHandValue() > DealerHandValue) {
    Bust(Flags::DEALER);
  } else {
    Bust(Flags::PLAYER);
  }
  GameFlag = Flags::StartPlayerTurn;
}

void BlackJack::Bust(int flag) {
  if (flag == Flags::DEALER) {
    std::cout << "Win\n";
  } else if (flag == Flags::PLAYER) {
    std::cout << "Lose\n";
  } else {
    std::cout << "Push\n";
  }
  Flags::SetFlags(Flags::MAIN_MENU);
}

void BlackJack::PlayerTurn() {
  if (GameFlag == Flags::StartPlayerTurn) {
    std::cout << "Press \"H\" to hit\n";
    std::cout << "Press \"S\" to stand\n";
  }
  if (CheckHandValue() > 21) {
    Bust(Flags::PLAYER);
  }
  int playerChoice;
  switch (GetKeyPressed()) {
    case KEY_S:
      std::cout << "Player stand\n";
      GameFlag = Flags::DealerMove;
      break;
    case KEY_H:
      Hit(Flags::PLAYER);
      if (CheckHandValue() > 21) {
        Bust(1);
      }
      break;
    default: GameFlag = Flags::WaitForInput; break;
  }
}

void BlackJack::Hit(int turn) {
  switch (turn) {
    case Flags::PLAYER: player.push_back(deck.DealCard()); break;
    case Flags::DEALER: dealer.push_back(deck.DealCard()); break;
  }
}

int BlackJack::CheckHandValue() {
  int PlayerHandValue = 0;
  for (Card card : player) {
    PlayerHandValue += card.GetCardValue();
  }
  return PlayerHandValue;
}

// Deal Cards To player and dealer
void BlackJack::DealCards(int turn) {
  switch (turn) {
    case Flags::PLAYER:
      for (int i = 0; i < 2; i++) {
        player.push_back(deck.DealCard());
        // std::cout << deck.GetDeck().back().GetCardName() << "\n";
      }
      for (Card card : player) {
        std::cout << card.GetCardName() << "\n";
      }
      break;
    case Flags::DEALER:
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
