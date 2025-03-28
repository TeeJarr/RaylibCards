#include "Deck.hpp"
#include <algorithm>
#include <random>
#include <vector>

Deck::Deck(int a_NumDeck) : NumDecks(a_NumDeck) {
  CreateDeck();
}

void Deck::CreateDeck() {
  for (int DeckNum = 0; DeckNum < NumDecks; DeckNum++) {

    for (int DeckNum = 0; DeckNum < NumDecks; DeckNum++) {
      // Number Cards
      for (int val = 1; val < 10; val++) {
        for (int suit = 0; suit < 4; suit++) {
          Card newCard(val, suit, 0);
          deck.push_back(newCard);
        }
      }

      // Face Cards
      for (int val = 0; val < 4; val++) {
        for (int suit = 0; suit < 4; suit++) {
          Card newCard(10, suit, val);
          deck.push_back(newCard);
        }
      }
    }
  }
}

Card Deck::DealCard() {
  Card card = deck.back();
  deck.pop_back();
  return card;
}

std::vector<Card> Deck::ShuffleDeck() {
  std::random_device rd;
  static std::mt19937 rng(rd());

  // twice to decrease the odds of cards not being broken up
  std::shuffle(deck.begin(), deck.end(), rng);

  return deck;
}

std::vector<Card> Deck::GetDeck() const {
  return deck;
}
