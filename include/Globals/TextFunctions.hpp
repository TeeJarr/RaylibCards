#pragma once
#include "raylib.h"

namespace text
{
    Vector2 CenterText(const char* Str, float FontSize, Font TextFont);
    Rectangle GetTextBounds(Vector2 TopLeft, Vector2 MeasureValue);
} // namespace text
