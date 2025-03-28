#pragma once
#include "Card.hpp"
#include <vector>

class Deck
{
  public:
  Deck(int a_NumDecks);
  void CreateDeck();
  Card DealCard();
  std::vector<Card> ShuffleDeck();
  std::vector<Card> GetDeck() const;

  private:
  int NumDecks;
  int DeckSize;
  std::vector<Card> deck;
};
