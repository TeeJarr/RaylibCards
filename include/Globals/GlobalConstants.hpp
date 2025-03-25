#pragma once
#include "Button.hpp"
#include <raylib.h>
#include <vector>

namespace GlobalConstants
{
    inline Vector2 ScreenSize{1280, 720};
    const constexpr char* ScreenTitle = "Card Games";
    inline float FontSize             = 48;
    inline std::vector<Button*> opts_btn_arr;
    inline std::vector<Button*> title_btn_arr;
    inline std::vector<Button*> sel_btn_arr;
} // namespace GlobalConstants
