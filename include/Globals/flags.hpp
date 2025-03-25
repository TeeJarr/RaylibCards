#pragma once

namespace Flags
{
    namespace ActiveMode
    {
        inline bool inMainMenu    = true;
        inline bool inOptionsMenu = false;
        inline bool inGame        = false;
    } // namespace ActiveMode
    void SetFlags(int sel);
} // namespace Flags
