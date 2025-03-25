#include "flags.hpp"
#include <iostream>

void Flags::SetFlags(int sel) {
    using namespace Flags::ActiveMode;
    switch (sel) {
    case 1:
        inGame        = true;
        inOptionsMenu = false;
        inMainMenu    = false;
        break;
    case 2:
        inOptionsMenu = true;
        inGame        = false;
        inMainMenu    = false;
        break;
    case 3:
        inMainMenu    = true;
        inGame        = false;
        inOptionsMenu = false;
        break;
    default:
        std::cout << "invalid flag";
        break;
    }
}
