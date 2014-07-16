#ifndef OL_INPUT_LISTENER_H
#define OL_INPUT_LISTENER_H

#include "../Reflection/OL_Interface.h"
#include "OL_KeyDef.h"

namespace OnLooker
{
    class Input;   
    //This is an interface
    class InputListener : public Reflection::Interface
    {
    public:
        InputListener();
        ~InputListener();
        virtual Reflection::Type getType();


    private:
        friend Input;

        virtual void onKeyPress(KeyCode::EKeyCode aKeyCode) = 0;
        virtual void onKeyRelease(KeyCode::EKeyCode aKeyCode) = 0;
        virtual void onMousePress(MouseCode::EMouseCode aButtonCode) = 0;
        virtual void onMouseRelease(MouseCode::EMouseCode aButtonCode) = 0;
        virtual void onMouseMove(float aPreviousX, float aPreviousY, float aMouseX, float aMouseY) = 0;
        virtual void onMouseScroll(float aPreviousScroll, float aScrollPosition) = 0;

        
    };
}

#endif