#pragma once
#include "Button.hpp"
#include "GlobalConstants.hpp"
#include "TextFunctions.hpp"
#include "raylib.h"
#include <vector>

class OptionsMenu
{
     public:
    OptionsMenu();
    ~OptionsMenu();
    void Loop();

     private:
    void Draw();
    void Update();
    void SetOptionsFlags();
    void DrawTitle();
    void UpdateButtons();
    void DrawButtons();
    void ChangeWindowSize();
    void ChangeButtonPos();

     private:
    const char* OptionsTitle = "Options";
    const char* str_720p     = "720p";
    const char* str_1080p    = "1080p";
    const char* str_1440p    = "1440p";

    Vector2 ResButton1080 = {(GlobalConstants::ScreenSize.x / 2.0f),
                             GlobalConstants::ScreenSize.y / 3.0f};
    Vector2 ResButton1440 = {(GlobalConstants::ScreenSize.x / 2.0f) * 0.8f,
                             GlobalConstants::ScreenSize.y / 3.0f};
    Vector2 ResButton720  = {(GlobalConstants::ScreenSize.x / 2.0f) * 1.2f,
                             GlobalConstants::ScreenSize.y / 3.0f};
    Button button1440p, button1080p, button720p;
};
