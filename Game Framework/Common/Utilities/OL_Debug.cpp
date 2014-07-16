#include "OL_Debug.h"
#include "OL_Console.h"

namespace OnLooker
{
    //Get a pointer to console
    Console * Debug::console = Console::getInstance();


    void Debug::initialize()
    {
        if(console == 0)
        {
            console = Console::getInstance();
        }
    }
    void Debug::destroy()
    {
        console->destroy();
    }
}