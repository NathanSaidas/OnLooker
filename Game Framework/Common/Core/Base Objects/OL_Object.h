#ifndef OL_OBJECT_H
#define OL_OBJECT_H

//#include "../../Reflection/OL_Reflection.h"
#include "../Reflection/OL_Class.h"
#include "../Reflection/OL_Type.h"

namespace OnLooker
{

    /*
    *   All objects have a type they must name
    */

    class MemoryManager;
    class PoolAllocator;

    //Remember
    //Virtual Method takes (Pure or not) takes 4 bytes for a pointer address
    
    class Object : public Reflection::Class
    {
    public:
        Object();
        virtual ~Object();


        virtual Reflection::Type getType();
        virtual Reflection::Type baseType();
        virtual Reflection::Type * instanceOf(int & aCount);

        //friend MemoryManager;
        //friend PoolAllocator;
    };
}

#endif