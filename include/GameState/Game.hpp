#pragma once
#include "Button.hpp"
#include "GlobalConstants.hpp"

class Game
{
  public:
  Game();
  ~Game();
  void Loop();

  private:
  void Draw();
  void Update();
  void DrawGameSelectors();
  void DrawBlackJack();

  public:
  void TestCards();

  private:
  const char* BlackJackText = "Black Jack";
  Vector2 BlackJackPos      = {GlobalConstants::ScreenSize.x / 2.0f,
                               GlobalConstants::ScreenSize.y / 10.0f};
  Button BlackJackButton;

  private:
};
