#include "flags.hpp"
#include <iostream>

void Flags::SetFlags(int sel) {
  switch (sel) {
    case GAME_SELECTOR : ActiveMode::ACTIVE_FLAG = GAME_SELECTOR; break;
    case OPTIONS_MENU  : ActiveMode::ACTIVE_FLAG = OPTIONS_MENU; break;
    case MAIN_MENU     : ActiveMode::ACTIVE_FLAG = MAIN_MENU; break;
    case GAME_BLACKJACK: ActiveMode::ACTIVE_FLAG = GAME_BLACKJACK; break;
    default            : std::cout << "invalid flag"; break;
  }
}
