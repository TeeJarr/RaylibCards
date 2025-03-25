#include "Button.hpp"

class MainMenu
{
     public:
    MainMenu();
    ~MainMenu();
    void Loop();

     private:
    void Draw();
    void Update();
    void SetMenuFlag(int selection);
    void DrawTitle();
    void DrawButtons();
    void CheckButtonUpdates();

     private:
    constexpr static const char* GameTitle = "Cards";
    const char* StartText;
    const char* OptionsText;
    Button StartButton;
    Button OptionsButton;
    int FontSize;
};
