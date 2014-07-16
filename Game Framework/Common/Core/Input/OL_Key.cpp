#include "OL_Key.h"
#include "../Reflection/OL_Reflection.h"

namespace OnLooker
{
    using namespace Reflection;
    Key::Key()
    {
    }
    Key::Key(KeyCode::EKeyCode aKeyCode) : HardWareControl()
    {
        m_KeyCode = aKeyCode;
    }
    
    Key::~Key()
    {
    
    }
    int Key::getCode()
    {
        return m_KeyCode;
    }
    //Reflection implementation
    Type Key::getType()
    {
        return TypeFactory::create("Key",Reflection::TypeID::KEY,sizeof(Key));
    }
    Type Key::baseType()
    {
        return HardWareControl::getType();
    }
    Type * Key::instanceOf(int & aCount)
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