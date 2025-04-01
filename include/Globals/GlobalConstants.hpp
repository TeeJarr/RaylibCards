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

  inline Font CardFont;
  inline Texture2D SpadeImage;
  inline Rectangle SpadeBounds   = {0, 0, 33.75, 45};
  inline Rectangle HeartBounds   = {33.75, 0, 33.75, 45};
  inline Rectangle ClubBounds    = {67.5, 0, 33.75, 45};
  inline Rectangle DiamondBounds = {101.25, 0, 33.75, 45};

} // namespace GlobalConstants
