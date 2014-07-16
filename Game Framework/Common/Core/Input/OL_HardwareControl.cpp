#include "OL_HardwareControl.h"
#include "../Reflection/OL_Reflection.h"

namespace OnLooker
{
    using namespace Reflection;

    HardWareControl::HardWareControl():Object()
    {

    }
    HardWareControl::~HardWareControl()
    {

    }
    ControlState::ControlState HardWareControl::state()
    {
        return m_State;
    }
    float HardWareControl::timePressed()
    {
        return m_TimePressed;
    }
    float HardWareControl::timeReleased()
    {
        return m_TimeReleased;
    }
    Type HardWareControl::getType()
    {
        return TypeFactory::create("HardwareControl",Reflection::TypeID::HARDWARE_CONTROL,sizeof(HardWareControl));
    }
    Type HardWareControl::baseType()
    {
        return Object::getType();
    }
    Type * HardWareControl::instanceOf(int & aCount)
    {
        int prevCount = 0;
        Type * prevType = Object::instanceOf(prevCount);
        aCount =  prevCount + 1;
        char ** names = new char * [1];
        int * typeIDs = new int[1];
        int * sizes = new int[1];

            

        names[0] = "Object";
        typeIDs[0] = Reflection::TypeID::OBJECT;
        sizes[0] = sizeof(Object);

        Type * types = Reflection::TypeFactory::create(names,typeIDs,sizes,aCount,prevType,prevCount);

        delete[]names;
        delete[]typeIDs;
        delete[]sizes;
        return types;
    }

    void HardWareControl::updateState()
    {
        if(m_State == ControlState::PRESS)
        {
            m_State = ControlState::DOWN;
        }
        else if(m_State == ControlState::RELEASE)
        {
            m_State = ControlState::UP;
        }
    }
}