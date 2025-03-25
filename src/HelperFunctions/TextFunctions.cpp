#include "TextFunctions.hpp"
#include "raylib.h"

Vector2 text::CenterText(const char* Str, float FontSize, Font TextFont) {
    float XValue = MeasureTextEx(TextFont, Str, FontSize, 1).x / 2.0f;
    float YValue = MeasureTextEx(TextFont, Str, FontSize, 1).y / 2.0f;

    return {XValue, YValue};
}

Rectangle text::GetTextBounds(Vector2 TopLeft, Vector2 MeasureValue) {
    return {TopLeft.x, TopLeft.y, MeasureValue.x, MeasureValue.y};
}
