#ifndef OL_TYPE_H
#define OL_TYPE_H

#include "OL_Primitive.h"

//Base class of every data type. Enum / Class
namespace OnLooker
{
    namespace Reflection
    {
        class TypeFactory;
        class Type : public Primitive
        {
        public:
            
            ~Type(){}
            bool operator ==(const Type & aRhs)
            {
                return aRhs.typeID == typeID;
            }
        protected:
            Type():Primitive(){}
            Type(char * aName, int aTypeID, int aSize)
            {
                name = aName;
                typeID = aTypeID;
                size = aSize;
            }
            
            int typeID;
            int size;

            

            friend TypeFactory;
        };
    }
}

#endif