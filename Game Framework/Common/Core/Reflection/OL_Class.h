#ifndef OL_CLASS_H
#define OL_CLASS_H


#include "OL_Type.h"

namespace OnLooker
{
    namespace Reflection
    {
        class Class //: public Type 
        {
        public:
            Class(){}
            ~Class(){}

            //3 Basic functions to establish a type
            virtual Type getType();
            virtual Type baseType();
            virtual Type * instanceOf(int & aCount);
        protected:
            
            
            //Field * fields; 
            //Function * functions;
        };
    }

}

#endif