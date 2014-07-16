#ifndef OL_BUTTON_H
#define OL_BUTTON_H

#include "OL_HardwareControl.h"

namespace OnLooker
{
    class Input;
    class Button : public HardWareControl
    {
    public:
        Button();
        Button(MouseCode::EMouseCode aMouseCode);
        ~Button();

        int getCode();
        //Reflection implementation
        virtual Reflection::Type getType();
        virtual Reflection::Type baseType();
        virtual Reflection::Type * instanceOf(int & aCount);
    protected:
        MouseCode::EMouseCode m_MouseCode;
        friend Input;
    };

}

#endif