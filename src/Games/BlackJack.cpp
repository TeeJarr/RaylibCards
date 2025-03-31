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
  DrawLineEx({GlobalConstants::ScreenSize.x / 2.0f, 0},
             {GlobalConstants::ScreenSize.x / 2.0f, GlobalConstants::ScreenSize.y}, 2, BLACK);
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

// Draw Section
void BlackJack::DrawPlayerHands() {
  float OffsetX     = 0;
  float offsetDelta = 0.2;
  OffsetX           = (offsetDelta * -1);

  for (Card card : player) {
    float CardPosX;
    if (player.size() % 2 == 0) {
      CardPosX =
          GlobalConstants::ScreenSize.x * (0.5 + OffsetX) + (card.GetCardSize().x * 0.15); // centers cards on gap between
    } else {
      CardPosX =
          GlobalConstants::ScreenSize.x * (0.5 + OffsetX) - card.GetCardSize().x * 0.5f; // center cards on center card
    }
    float CardPosY = GlobalConstants::ScreenSize.y * 0.55;
    OffsetX += offsetDelta;
    card.DrawCard({CardPosX, CardPosY});
  }
  // std::cout << player.size() << "\n";
}

void BlackJack::DrawDealerHands() {
  float Offset      = 0.1;
  float OffsetX     = 0;
  float offsetDelta = 0.2;
  OffsetX           = (offsetDelta * -1);

  for (Card card : dealer) {
    float CardPosX;
    if (dealer.size() % 2 == 0) {
      CardPosX =
          GlobalConstants::ScreenSize.x * (0.5 + OffsetX) + (card.GetCardSize().x * 0.15); // centers cards on gap between
    } else {
      CardPosX =
          GlobalConstants::ScreenSize.x * (0.5 + OffsetX) - card.GetCardSize().x * 0.5f; // center cards on center card
    }
    float CardPosY = GlobalConstants::ScreenSize.y * 0.05;
    OffsetX += offsetDelta;
    card.DrawCard({CardPosX, CardPosY});
  }
}

// Game Logic
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
  // std::cout << "Enter Number of Decks: ";
  // std::cin >> NumDecks;
  NumDecks = 1;
  return NumDecks;
}
