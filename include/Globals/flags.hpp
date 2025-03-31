#pragma once

namespace Flags
{
  void SetFlags(int sel);
  enum Flags {
    GAME_SELECTOR  = 1,
    OPTIONS_MENU   = 2,
    MAIN_MENU      = 3,
    GAME_BLACKJACK = 4,
  };
  enum BlackJackGameFlag {
    StartPlayerTurn = 0,
    WaitForInput    = 1,
    DealerMove      = 2,
  };
  enum PLAYER_CHOCIE {
    PLAYER = 0,
    DEALER = 1,
  };
  inline int ACTIVE_FLAG = MAIN_MENU;
} // namespace Flags
