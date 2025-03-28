#include "Card.hpp"
#include <iostream>
#include <string>
#include <utility>

Card::Card(const int a_CardValue, const int a_Suit, const int a_FaceFlag)
    : CardValue(a_CardValue), Suit(a_Suit), FaceFlag(a_FaceFlag) {
  if (CardValue == 1) {
    ChangeValue(11);
  }
}

Card::~Card() {
  // std::cout << "Card Destroyed\n";
}

void Card::swap(Card& other) noexcept {
  std::swap(this->CardValue, other.CardValue);
  std::swap(this->Suit, other.Suit);
  std::swap(this->FaceFlag, other.FaceFlag);
}

std::string Card::GetValueString() const {
  if (CardValue < 10) {
    return std::to_string(CardValue).c_str();
  } else if (CardValue == 11) {
    return "Ace";
  } else {
    switch (FaceFlag) {
      case Jack : return "Jack"; break;
      case Queen: return "Queen"; break;
      case King : return "King"; break;
      default   : return "10"; break;
    }
  }
}

const char* Card::GetSuitName() const {
  switch (Suit) {
    case Clubs  : return "Clubs";
    case Hearts : return "Hearts";
    case Diamond: return "Diamond";
    case Spade  : return "Spades";
    default     : return "";
  }
}

int Card::GetCardValue() const {
  return CardValue;
}

int Card::GetSuitValue() const {
  return Suit;
}

std::string Card::GetCardName() const {
  std::string FullName = GetValueString() + " of " + GetSuitName();
  return FullName;
}

void Card::ChangeValue(int NewValue) {
  CardValue = NewValue;
}
