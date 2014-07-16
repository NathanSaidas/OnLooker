#ifndef OL_HARDWARE_CONTROL_H
#define OL_HARDWARE_CONTROL_H

#include "../Base Objects/OL_Object.h"
#include "OL_KeyDef.h"

namespace OnLooker
{
    class Input;

    namespace ControlState
    {
        enum ControlState
        {
            PRESS,
            RELEASE,
            DOWN,
            UP
        };
    }


    class HardWareControl : public Object
    {
    public:
        HardWareControl();
        ~HardWareControl();


        //Override this to return the right code
        virtual int getCode() = 0;
            
        ControlState::ControlState state();
        float timePressed();
        float timeReleased();

        //Reflection implementation
        virtual Reflection::Type getType();
        virtual Reflection::Type baseType();
        virtual Reflection::Type * instanceOf(int & aCount);
    protected:
        void updateState();
        ControlState::ControlState m_State; //Down and Up in this case
        float m_TimePressed;
        float m_TimeReleased;

        //Friend the Input Manager
        friend Input;
    };

}

#endif