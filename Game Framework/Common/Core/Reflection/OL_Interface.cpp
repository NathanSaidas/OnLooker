#include "OL_Interface.h"

#include "OL_TypeFactory.h"
#include "OL_Types.h"
namespace OnLooker
{
    namespace Reflection
    {
        Type Interface::getType()
        {
            return TypeFactory::create("Interface",TypeID::INTERFACE,sizeof(Interface));
        }
    }
}