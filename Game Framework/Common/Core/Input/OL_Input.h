#ifndef OL_INPUT_H
#define OL_INPUT_H

#include "../Base Objects/OL_Object.h"
#include "../Base Objects/OL_Array.h"
#include "OL_InputListener.h"
#include "OL_KeyDef.h"

namespace OnLooker
{
    class Window;
    class Main;
    class Key;
    class Button;
    class PoolAllocator;

    class Input : public Object
    {
    public:
        static Input * instance();
        static void destroy();
        //Get the mouse position
        void mousePosition(float & x, float & y);

        //Check mouse button states
        bool getMouseButton(MouseCode::EMouseCode aCode);
        bool getMouseButtonDown(MouseCode::EMouseCode aCode);
        bool getMouseButtonUp(MouseCode::EMouseCode aCode);
        //Check key states
        bool getKey(KeyCode::EKeyCode aCode);
        bool getKeyDown(KeyCode::EKeyCode aCode);
        bool getKeyUp(KeyCode::EKeyCode aCode);

        //Get delta mouse positions
        float deltaMouseX();
        float deltaMouseY();
        float deltaMouseScroll();

        //Input Listener registeration.
        void registerListener(InputListener * aListener);
        void unregisterListener(InputListener * aListener);
        

        virtual Reflection::Type getType();
        virtual Reflection::Type baseType();
        virtual Reflection::Type * instanceOf(int & aCount);
    private:
        Input();
        ~Input();
        static Input * s_Instance;

        //

        void handleStates();
        //Functions for window to use
        void handleKeyEvent(int aKey, int aAction);
        void handleMouseButtonEvent(int aButton, int aAction);
        void handleMouseMove(float aXPosition, float aYPosition);
        void handleMouseScroll(float aXAxis, float aYAxis);

        
        Key * m_Keys;
        Button * m_Buttons;
        //Buffered State Variables
        float m_BCurrentMouseX;
        float m_BCurrentMouseY;
        float m_BPreviousMouseX;
        float m_BPreviousMouseY;

        float m_BCurrentMouseScroll;
        float m_BPreviousMouseScroll;

        //Current State Variables
        float m_CCurrentMouseX;
        float m_CCurrentMouseY;
        float m_CPreviousMouseX;
        float m_CPreviousMouseY;

        float m_CCurrentMouseScroll;
        float m_CPreviousMouseScroll;

        //List of Listeners
        Array<InputListener *,InputListener> m_Listeners;


        friend Window;
        friend Main;
        friend PoolAllocator;
    };
}

#endif