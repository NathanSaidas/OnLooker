#ifndef OL_INTERFACE_H
#define OL_INTERFACE_H

#include "OL_Type.h"

namespace OnLooker
{
    namespace Reflection
    {
        class Interface
        {
            public:
                virtual Type getType();
        };
        
    }
}

#endif