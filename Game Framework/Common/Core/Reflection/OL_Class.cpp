#include "OL_Class.h"
#include "OL_Types.h"
#include "OL_TypeFactory.h"

namespace OnLooker
{
    namespace Reflection
    {
        //Class Methods
        Type Class::getType()
        {
            return TypeFactory::create("Class",TypeID::CLASS,sizeof(Class));
        }
        Type Class::baseType()
        {
            return TypeFactory::create("NONE",TypeID::NONE,0);
        }
        Type * Class::instanceOf(int & aCount)
        {
            //Create an array of names, type ids and sizes and send them into the factory
            char ** names = 0;
            int * typeIDs = 0;
            int * sizes = 0;
            int numberOfTypes = 0;
            return TypeFactory::create(names,typeIDs,sizes,numberOfTypes);
        }
    }
}