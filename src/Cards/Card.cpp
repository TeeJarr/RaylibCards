#include "Card.hpp"
#include "raylib.h"
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
    return "A";
  } else {
    switch (FaceFlag) {
      case Jack : return "J"; break;
      case Queen: return "Q"; break;
      case King : return "K"; break;
      default   : return "10"; break;
    }
  }
}

void Card::DrawCard(Vector2 CardPos) const {
  Color CardColor;
  if (Suit == Clubs || Suit == Spade) {
    CardColor = BLACK;
  } else {
    CardColor = RED;
  }
  DrawRectangleRounded(GetCardRec(CardPos), Roundness, Segments, WHITE);
  DrawRectangleRoundedLinesEx(GetCardRec(CardPos), Roundness, Segments, LineThick, CardColor);

  Vector2 textPos  = {CardPos.x * 1.01f, CardPos.y * 1.01f};
  Vector2 textSize = MeasureTextEx(GetFontDefault(), GetValueString().c_str(), 36, 1);
  DrawTextEx(CardFont, GetValueString().c_str(), textPos, CardFontSize, Spacing, CardColor);
  DrawTextEx(CardFont, GetSuitLetter(), {textPos.x, textPos.y + textSize.y}, CardFontSize, Spacing, CardColor);

  Vector2 secondPos = {((CardPos.x + width) - textSize.x) * 0.99f, ((CardPos.y + height) - textSize.y) * 0.99f};
  DrawTextEx(CardFont, GetValueString().c_str(), secondPos, CardFontSize, Spacing, CardColor);
  DrawTextEx(CardFont, GetSuitLetter(), {secondPos.x, secondPos.y - textSize.y}, CardFontSize, Spacing, CardColor);
  Vector2 origin = {secondPos.x - (textSize.x * 0.5f), secondPos.y - (textSize.y * 0.5f)};
  // DrawTextPro(CardFont, GetValueString().c_str(), secondPos, origin, roation, CardFontSize, Spacing, BLACK);
}

Vector2 Card::GetCardSize() const {
  return {width, height};
}

Rectangle Card::GetCardRec(Vector2 CardPos) const {
  return {CardPos.x, CardPos.y, width, height};
}

const char* Card::GetSuitLetter() const {
  switch (Suit) {
    case Clubs  : return "C";
    case Hearts : return "H";
    case Diamond: return "D";
    case Spade  : return "S";
    default     : return "";
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
