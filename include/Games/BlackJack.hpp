#pragma once
#include "Deck.hpp"
#include "flags.hpp"
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

  int GameFlag = Flags::StartPlayerTurn;

  int DealerHandValue;
  int PlayerHandValue;
};
