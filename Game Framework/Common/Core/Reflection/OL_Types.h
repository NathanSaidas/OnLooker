#ifndef OL_TYPES
#define OL_TYPES

namespace OnLooker
{

    namespace Reflection
    {
        namespace TypeID
        {
            //ADD TYPES TO LIST
            enum TypeID
            {
                INVALID_ID = 0,
                NONE,
                CLASS,
                INTERFACE,
                OBJECT,
                STRING,
                ARRAY,
                ALLOCATOR,
                POOL_ALLOCATOR,
                MEMORY_MANAGER,
                HARDWARE_CONTROL,
                KEY,
                BUTTON,
                INPUT,
                INPUT_LISTENER,
                WINDOW,
                UNIQUE_NUMBER_GENERATOR,
                
            };
        }
    }

}
#endif
