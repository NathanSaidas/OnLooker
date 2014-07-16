#ifndef OL_UNIQUE_NUMBER_GENERATOR_H
#define OL_UNIQUE_NUMBER_GENERATOR_H


#include "../Core/Base Objects/OL_Object.h"
#include "../Core/Base Objects/OL_Array.h"

namespace OnLooker
{
    #define UNG UniqueNumberGenerator

    class UniqueNumberGenerator : public Object
    {
    public:
        UniqueNumberGenerator();
        ~UniqueNumberGenerator();


        int getUniqueNumber();
        void returnUniqueNumber(int aNumber);

        virtual Reflection::Type getType();
        virtual Reflection::Type baseType();
        virtual Reflection::Type * instanceOf(int & aCount);

    private:
        int m_NextNumber;
        Array<int,int> m_FreeNumberList;
        
    };
}

#endif