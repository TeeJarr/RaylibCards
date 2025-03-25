#pragma once

#include "raylib.h"
class Button
{
     public:
    Button(const char* a_ButtonText, Vector2 a_ButtonLocation, Color a_ButtonColor);

     public:
    void Draw();
    bool isClicked();
    void UpdateButtonPos(Vector2 newButtonLocation);

     private:
    Rectangle GetBounds();
    void DrawBounds();

     private:
    const char* ButtonText;
    Vector2 ButtonLocation;
    Color ButtonColor;
};
