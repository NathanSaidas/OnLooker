#ifndef OL_OPERATORS_H
#define OL_OPERATORS_H

#include "OL_Type.h"
#include "OL_TypeFactory.h"
#include "OL_Class.h"
#include "OL_Enum.h"

namespace OnLooker
{
    namespace Reflection
    {
        //Reflection Operators
        inline char * nameOf(Type & aType)
        {
            return TypeFactory::nameOf(aType);
        }
        inline char * nameOf(Class & aClass)
        {
            return TypeFactory::nameOf(aClass.getType());
        }
        inline char * nameOf(Class * aClass)
        {
            if(aClass != nullptr)
            {
                return TypeFactory::nameOf(aClass->getType());
            }
            return "";
        }
        inline char * nameOf(Enum aEnum)
        {
            return TypeFactory::nameOf(aEnum);
        }
        inline char * nameOf(Enum * aEnum)
        {
            if(aEnum == nullptr)
            {
                return "";
            }
            return TypeFactory::nameOf((*aEnum));
        }
        inline int typeID(Type & aType)
        {
            return TypeFactory::typeID(aType);
        }
        inline int typeID(Class & aClass)
        {
            return TypeFactory::typeID(aClass.getType());
        }
        inline int typeID(Class * aClass)
        {
            if(aClass != nullptr)
            {
                return TypeFactory::typeID(aClass->getType());
            }
            return 0;
        }
        
        template<class T>
        Type typeOf()
        {
            T type;
            return type.getType();
        }

        inline int sizeOf(Type & aType)
        {
            return TypeFactory::sizeOf(aType);
        }
        inline int sizeOf(Class & aClass)
        {
            return TypeFactory::sizeOf(aClass.getType());
        }
        inline int sizeOf(Class * aClass)
        {
            if(aClass != nullptr)
            {
                return TypeFactory::sizeOf(aClass->getType());
            }
            return 0;
        }
    }
}

#endif