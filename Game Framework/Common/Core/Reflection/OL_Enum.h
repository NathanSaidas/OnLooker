#ifndef OL_ENUM_CONSTANT_H
#define OL_ENUM_CONSTANT_H

#include "OL_Primitive.h"
#include "OL_Type.h"

#include "../Base Objects/OL_Object.h"

namespace OnLooker
{
    namespace Reflection
    {
        //template<class TYPE,class DEREFERENCED_TYPE>
        //class Array;

        

        class TypeFactory;
        class Enum : public Primitive
        {
        public:
            Enum():Primitive(){}
            Enum(int aValue,char * aName):Primitive(){value = aValue; name = aName;}
            ~Enum(){}
            int value;



            int & operator= (const int & aValue)
            {
                value = aValue;
                return value;
            }
            int operator+(const int & aValue)
            {
                return value + aValue;
            }
            int operator-(const int & aValue)
            {
                return value - aValue;
            }
            int operator+=(const int & aValue)
            {
                value += aValue;
                return value;
            }
            int operator-=(const int & aValue)
            {
                value -= aValue;
                return value;
            }
            bool operator==(int aValue)
            {
                return (aValue == value);
            }
            
            friend TypeFactory;
        };

        //class Enum : Type
        //{
        //public:
        //    Enum();
        //    ~Enum();
        //    
        //    //EnumConstant getEnum(char * aName);
        //    //EnumConstant getEnum(int aEnum);
        //    //void addEnum(char * aName);
        //    //int count();
        //private:
        //    //Array<EnumConstant,EnumConstant> m_Enums;
        //    int m_Count;
        //};
    }
}

#endif