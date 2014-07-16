#ifndef OL_TYPE_FACTORY_H
#define OL_TYPE_FACTORY_H

#include "OL_Type.h"
#include "OL_Enum.h"

namespace OnLooker
{
    namespace Reflection
    {
        //Type Accessor
        class TypeFactory
        {
        public:
            //Create methods
            static Type create(char * aName, int aTypeID, int aSize);
            static Type * create(char ** aName, int * aTypeID, int * aSize, int aCount);
            static Type * create(char ** aName, int * aTypeID, int * aSize, int aCount, Type * aPreviousTypes, int aPreviousCount);
            static Type * create(Type aType, int aCount, Type * aPreviousTypes, int aPreviousCount);
            //Operators
            static char * nameOf(Enum & aEnum);
            static char * nameOf(Type aType);
            static int typeID(Type aType);
            static int sizeOf(Type aType);
        };
    }
}

#endif