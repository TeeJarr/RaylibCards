#pragma once
#include "string"

class Card
{
  public:
  Card(const int CardValue, const int Suit, const int a_FaceFlag);
  void swap(Card& other) noexcept;
  ~Card();

  public:
  std::string GetCardName() const;
  int GetCardValue() const;
  int GetSuitValue() const;
  const char* GetSuitName() const;
  std::string GetValueString() const;
  void ChangeValue(int NewValue);

  private:
  enum Suits { Clubs, Hearts, Diamond, Spade };
  enum FaceFlags { Jack, Queen, King };
  int CardValue;
  int Suit;
  int FaceFlag;
};
