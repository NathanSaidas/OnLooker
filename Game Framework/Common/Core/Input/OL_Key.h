#ifndef OL_KEY_H
#define OL_KEY_H

#include "OL_HardwareControl.h"

namespace OnLooker
{
    class Input;

    class Key : public HardWareControl
    {
    public:
        Key();
        Key(KeyCode::EKeyCode aKeyCode);
        ~Key();

        int getCode();
        //Reflection implementation
        virtual Reflection::Type getType();
        virtual Reflection::Type baseType();
        virtual Reflection::Type * instanceOf(int & aCount);
    protected:
        KeyCode::EKeyCode m_KeyCode;

        friend Input;
    };
}

#endif