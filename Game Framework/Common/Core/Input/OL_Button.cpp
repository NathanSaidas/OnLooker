#include "OL_Button.h"
#include "../Reflection/OL_Reflection.h"

namespace OnLooker
{
    using namespace Reflection;
    Button::Button()
    {

    }
    Button::Button(MouseCode::EMouseCode aMouseCode)
    {
        m_MouseCode = aMouseCode;
    }
    Button::~Button()
    {
    }

    int Button::getCode()
    {
        return m_MouseCode;
    }
    //Reflection implementation
    Type Button::getType()
    {
        return TypeFactory::create("Button",TypeID::BUTTON,sizeof(Button));
    }
    Type Button::baseType()
    {
        return HardWareControl::getType();
    }
    Type * Button::instanceOf(int & aCount)
    {
        int prevCount = 0;
        Type * prevType = Object::instanceOf(prevCount);
        aCount =  prevCount + 1;
        char ** names = new char * [1];
        int * typeIDs = new int[1];
        int * sizes = new int[1];
    
            
    
        names[0] = "HardWareControl";
        typeIDs[0] = Reflection::TypeID::HARDWARE_CONTROL;
        sizes[0] = sizeof(HardWareControl);
    
        Type * types = Reflection::TypeFactory::create(names,typeIDs,sizes,aCount,prevType,prevCount);
    
        delete[]names;
        delete[]typeIDs;
        delete[]sizes;
        return types;
    }
}