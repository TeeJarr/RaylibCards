#include "Button.hpp"
#include "GlobalConstants.hpp"
#include "TextFunctions.hpp"
#include "raylib.h"
#include <iostream>

Button::Button(const char* a_ButtonText, Vector2 a_ButtonLocation, Color a_ButtonColor)
    : ButtonText(a_ButtonText), ButtonLocation(a_ButtonLocation), ButtonColor(a_ButtonColor) {}

void Button::Draw() {
    DrawBounds();
    DrawTextEx(GetFontDefault(), ButtonText,
               {ButtonLocation.x -
                    text::CenterText(ButtonText, GlobalConstants::FontSize, GetFontDefault()).x,
                ButtonLocation.y -
                    text::CenterText(ButtonText, GlobalConstants::FontSize, GetFontDefault()).y},
               GlobalConstants::FontSize, 1.0, ButtonColor);
}

void Button::DrawBounds() {
    DrawRectangleRec(GetBounds(), WHITE);
}

Rectangle Button::GetBounds() {
    return {ButtonLocation.x -
                text::CenterText(ButtonText, GlobalConstants::FontSize, GetFontDefault()).x,
            ButtonLocation.y -
                text::CenterText(ButtonText, GlobalConstants::FontSize, GetFontDefault()).y,
            MeasureTextEx(GetFontDefault(), ButtonText, GlobalConstants::FontSize, 1).x,
            MeasureTextEx(GetFontDefault(), ButtonText, GlobalConstants::FontSize, 1).y};
}

bool Button::isClicked() {
    if (CheckCollisionPointRec(GetMousePosition(), GetBounds()) &&
        IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        return true;
    } else {
        return false;
    }
}

void Button::UpdateButtonPos(Vector2 newButtonLocation) {
    ButtonLocation = newButtonLocation;
}
