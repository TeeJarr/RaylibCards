#pragma once
#include "Deck.hpp"
#include <vector>

class BlackJack
{
  public:
  BlackJack();

  public:
  void Loop();
  void Draw();
  void Update();

  private:
  void DealCards(int turn);
  int GetNumDecks();
  void DrawPlayerHands();
  void DrawDealerHands();
  void Hit(int turn);
  void DealerTurn();
  void PlayerTurn();
  void Bust();

  private:
  std::vector<Card> player;
  std::vector<Card> dealer;
  int NumDecks;
  Deck deck;
  int NumPlayers = 1;

  enum GameFlag {
    StartPlayerTurn = 0,
    WaitForInput    = 1,
    DealerMove      = 2,
  };
  int GameFlag = StartPlayerTurn;

  int DealerHandValue = 0;
  int PlayerHandValue = 0;
};
