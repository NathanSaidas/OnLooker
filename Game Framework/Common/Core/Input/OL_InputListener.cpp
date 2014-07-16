#include "OL_InputListener.h"
#include "../Reflection/OL_Reflection.h"


namespace OnLooker
{
    using namespace Reflection;
    InputListener::InputListener() : Interface()
    {

    }
    InputListener::~InputListener()
    {

    }


    Type InputListener::getType()
    {
        return TypeFactory::create("InputListener",TypeID::INPUT_LISTENER,sizeof(InputListener));
    }
}
