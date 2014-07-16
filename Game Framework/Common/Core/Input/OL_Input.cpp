#include "OL_Input.h"
#include "OL_Key.h"
#include "OL_Button.h"
#include "../Memory/OL_Memory.h"
#include "../Reflection/OL_Reflection.h"
#include "../../Libraries/OL_OpenGL.h"



namespace OnLooker
{
#define NUMBER_OF_KEYS 350
#define NUMBER_OF_MOUSE_BUTTONS 8

    using namespace KeyCode;
    using namespace MouseCode;
    using namespace Reflection;

    Input * Input::s_Instance = 0;
    Input * Input::instance()
    {
        if(s_Instance == 0)
        {
            s_Instance = Memory::instantiate<Input>();
        }
        return s_Instance;
    }
    void Input::destroy()
    {
        if(s_Instance != 0)
        {
            s_Instance = Memory::destroy<Input>(s_Instance);
        }
    }

    Input::Input()
    {
        //Default State

        m_Keys = Memory::instantiate<Key>(KeyCode::COUNT);
        m_Buttons = Memory::instantiate<Button>(MouseCode::COUNT);


        for(int i = 0; i < KeyCode::COUNT; i++)
        {
            m_Keys[i].m_KeyCode = (KeyCode::EKeyCode)i;
            m_Keys[i].m_State = ControlState::UP;
            m_Keys[i].m_TimePressed = 0.0f;
            m_Keys[i].m_TimeReleased = 0.0f;
        }
        for(int i = 0; i < MouseCode::COUNT; i++)
        {
            m_Buttons[i].m_MouseCode = (MouseCode::EMouseCode)i;
            m_Buttons[i].m_State = ControlState::UP;
            m_Buttons[i].m_TimePressed = 0.0f;
            m_Buttons[i].m_TimeReleased = 0.0f;
        }

        m_BCurrentMouseX = 0.0f;
        m_BCurrentMouseY = 0.0f;
        m_BPreviousMouseX = 0.0f;
        m_BPreviousMouseY = 0.0f;
        m_BPreviousMouseScroll = 0.0f;
        m_BCurrentMouseScroll = 0.0f;
        
        m_CCurrentMouseX = 0.0f;
        m_CCurrentMouseY = 0.0f;
        m_CPreviousMouseX = 0.0f;
        m_CPreviousMouseY = 0.0f;
        m_CPreviousMouseScroll = 0.0f;
        m_CCurrentMouseScroll = 0.0f;
        
    }
    Input::~Input()
    {
        m_Keys = Memory::destroy<Key>(m_Keys,KeyCode::COUNT);
        m_Buttons = Memory::destroy<Button>(m_Buttons,MouseCode::COUNT);
    }
    void Input::mousePosition(float & x, float & y)
    {
        x = m_CCurrentMouseX;
        y = m_CCurrentMouseY;
    }
    bool Input::getMouseButton(MouseCode::EMouseCode aCode)
    {
        if(aCode >= 0 && aCode < EMouseCode::COUNT)
        {
            return m_Buttons[aCode].state() == ControlState::DOWN || m_Buttons[aCode].state() == ControlState::PRESS;
        }
        return false;
    }
    bool Input::getMouseButtonDown(MouseCode::EMouseCode aCode)
    {
        if(aCode >= 0 && aCode < EMouseCode::COUNT)
        {
            return m_Buttons[aCode].state() == ControlState::PRESS;
        }
        return false;
    }
    bool Input::getMouseButtonUp(MouseCode::EMouseCode aCode)
    {
        if(aCode >= 0 && aCode < EMouseCode::COUNT)
        {
            return m_Buttons[aCode].state() == ControlState::RELEASE;
        }
        return false;
    }
    bool Input::getKey(KeyCode::EKeyCode aCode)
    {
        if(aCode >= 0 && aCode < EKeyCode::COUNT)
        {
            return m_Keys[aCode].state() == ControlState::DOWN || m_Keys[aCode].state() == ControlState::PRESS;
        }
        return false;
    }
    bool Input::getKeyDown(KeyCode::EKeyCode aCode)
    {
        if(aCode >= 0 && aCode < EKeyCode::COUNT)
        {
            return m_Keys[aCode].state() == ControlState::PRESS;
        }
        return false;
    }
    bool Input::getKeyUp(KeyCode::EKeyCode aCode)
    {
        if(aCode >= 0 && aCode < EKeyCode::COUNT)
        {
            return m_Keys[aCode].state() == ControlState::RELEASE;
        }
        return false;
    }
    float Input::deltaMouseX()
    {
        return abs(m_CCurrentMouseX - m_CPreviousMouseX);
    }
    float Input::deltaMouseY()
    {
        return abs(m_CCurrentMouseY - m_CPreviousMouseY);
    }
    float Input::deltaMouseScroll()
    {
        return abs(m_CCurrentMouseScroll - m_CPreviousMouseScroll);
    }
    void Input::registerListener(InputListener * aListener)
    {
        m_Listeners.addElement(aListener);
    }
    void Input::unregisterListener(InputListener * aListener)
    {
        m_Listeners.removeElement(aListener);
    }


    Type Input::getType()
    {
        return TypeFactory::create("Input",TypeID::INPUT,sizeof(Input));
    }
    Type Input::baseType()
    {
        return Object::getType();
    }

    Type * Input::instanceOf(int & aCount)
    {
        int prevCount = 0;
        Type * prevType = Object::instanceOf(prevCount);
        aCount =  prevCount + 1;
        char ** names = new char * [1];
        int * typeIDs = new int[1];
        int * sizes = new int[1];
    
            
    
        names[0] = "Object";
        typeIDs[0] = Reflection::TypeID::OBJECT;
        sizes[0] = sizeof(Object);
    
        Type * types = Reflection::TypeFactory::create(names,typeIDs,sizes,aCount,prevType,prevCount);
    
        delete[]names;
        delete[]typeIDs;
        delete[]sizes;
        return types;
    }

    void Input::handleStates()
    {
        for(int i = 0; i < KeyCode::COUNT; i++)
        {
            m_Keys[i].updateState();
        }
        for(int i = 0; i < MouseCode::COUNT; i++)
        {
            m_Buttons[i].updateState();
        }
        m_CCurrentMouseX = m_BCurrentMouseX;
        m_CCurrentMouseY = m_BCurrentMouseY;
        m_CCurrentMouseScroll = m_BCurrentMouseScroll;
        m_CPreviousMouseX = m_BPreviousMouseX;
        m_CPreviousMouseY = m_BPreviousMouseY;
        m_CPreviousMouseScroll = m_BPreviousMouseScroll;
    }

    void Input::handleKeyEvent(int aKey, int aAction)
    {
        if(aAction == GLFW_RELEASE)
        {
            m_Keys[aKey].m_State = ControlState::RELEASE;
            if(m_Listeners.count() > 0)
            {
                for(int i = 0; i < m_Listeners.count(); i++)
                {
                    m_Listeners[i]->onKeyRelease((KeyCode::EKeyCode)aKey);
                }
            }
        }
        else if(aAction == GLFW_PRESS)
        {
            m_Keys[aKey].m_State = ControlState::PRESS;
            if(m_Listeners.count() > 0)
            {
                for(int i = 0; i < m_Listeners.count(); i++)
                {
                    m_Listeners[i]->onKeyPress((KeyCode::EKeyCode)aKey);
                }
            }
        }
        
    }
    void Input::handleMouseButtonEvent(int aButton, int aAction)
    {
        if(aAction == GLFW_RELEASE)
        {
            m_Buttons[aButton].m_State = ControlState::RELEASE;
            if(m_Listeners.count() > 0)
            {
                for(int i = 0; i < m_Listeners.count(); i++)
                {
                    m_Listeners[i]->onMouseRelease((MouseCode::EMouseCode)aButton);
                }
            }
        }
        else if(aAction == GLFW_PRESS)
        {
            m_Buttons[aButton].m_State = ControlState::PRESS;
            if(m_Listeners.count() > 0)
            {
                for(int i = 0; i < m_Listeners.count(); i++)
                {
                    m_Listeners[i]->onMousePress((MouseCode::EMouseCode)aButton);
                }
            }
        }
    }
    void Input::handleMouseMove(float aXPosition, float aYPosition)
    {
        m_BPreviousMouseX = m_BCurrentMouseX;
        m_BPreviousMouseY = m_BCurrentMouseY;
        m_BCurrentMouseX = aXPosition;
        m_BCurrentMouseY = aYPosition;
        if(m_Listeners.count() > 0)
        {
            for(int i = 0; i < m_Listeners.count(); i++)
            {
                m_Listeners[i]->onMouseMove(m_BPreviousMouseX,m_BPreviousMouseY,m_BCurrentMouseX,m_BCurrentMouseY);
            }
        }
    }
    void Input::handleMouseScroll(float aXAxis, float aYAxis)
    {
        m_BPreviousMouseScroll = m_BCurrentMouseScroll;
        m_BCurrentMouseScroll += aYAxis;
        if(m_Listeners.count() > 0)
        {
            for(int i = 0; i < m_Listeners.count(); i++)
            {
                m_Listeners[i]->onMouseScroll(m_BPreviousMouseScroll,m_BCurrentMouseScroll);
            }
        }
    }
    
}

