#ifndef OL_WINDOW_H
#define OL_WINDOW_H

#include "../Base Objects/OL_Object.h"
#include "../Base Objects/OL_String.h"

struct GLFWwindow;

namespace OnLooker
{
    /*
    *   Class: Window
    *   Base Class: N/A
    *   Description: Helps create and sort out window functions such as creating the window
    *   and handling input from the window.
    *   Date Modified: 02/03/2014 by Nathan Hanlan
    */
    class Window : public Object
    {
        //Methods
    public:
        /*
        *   Function: Window
        *   Return Type: Constructor
        *   Description: Setups up window defaults
        *   Parameters: N/A
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        Window();
        /*
        *   Function: Window
        *   Return Type: Constructor
        *   Description: Setups up window defaults with parameters
        *   Parameters: @aWidth - The width of the window
        *   @aHeight - The height of the window
        *   @aWindowName - The title of the window
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        Window(int aWidth, int aHeight, String aWindowName);
        /*
        *   Function: Window
        *   Return Type: Destructor
        *   Description: calls destroy to destroy any initialized variables
        *   Parameters: N/A
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        ~Window();

        void onCreate(int aWidth, int aHeight, String aWindowName);
       
        /*
        *   Function: createWindow
        *   Return Type: bool
        *   Description: creates the window and returns true for successful or false for
        *   unsuccessful
        *   Parameters: N/A
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        bool createWindow();
        /*
        *   Function: destroy
        *   Return Type: void
        *   Description: Free's any memory allocated from the window
        *   Parameters: N/A
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        void destroy();
        /*
        *   Function: getWindowHandle
        *   Return Type: GLFWwindow
        *   Description: returns the handle to the window
        *   Parameters: N/A
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        GLFWwindow * getWindowHandle();

        /*
        *   Function: getWindowWidth
        *   Return Type: int
        *   Description: returns the width of the widnow
        *   Parameters: N/A
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        int getWindowWidth();
        /*
        *   Function: getWindowHeight
        *   Return Type: int
        *   Description: returns the height of the window
        *   Parameters: N/A
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        int getWindowHeight();
        /*
        *   Function: getWindowName
        *   Return Type: string
        *   Description: returns the name of the window name
        *   Parameters: N/A
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        String getWindowTitle();

        /*
        *   Function: shouldWindowClose
        *   Return Type: int
        *   Description: returns if the window should close
        *   Parameters: N/A
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        int shouldWindowClose();
        /*
        *   Function: getTime
        *   Return Type: double
        *   Description: calls glfwGetTime
        *   Parameters: N/A
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        static double getTime();
        /*
        *   Function: pollEvents
        *   Return Type: void
        *   Description: calls glfwPollEvents
        *   Parameters: N/A
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        void pollEvents();
        /*
        *   Function: swapBuffers
        *   Return Type: void
        *   Description: calls glfwSwapBuffers
        *   Parameters: N/A
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        void swapBuffers();

        


        //Methods
    private:
        //GLFW Callback methods
        /*
        *   GLFW Error callback
        *   aError: The error code
        *   aDescription: A UTF-8 encoded string describing the error
        */
        static void m_ErrorCallback(int aError, const char * aDescription);
        /*
        *   GLFW Keyboard input callback method
        *   aWindow: The window that recieved the event
        *   aKey: The keyboard key that was pressed or released
        *   aScanCode: The system-specific scancode of the key
        *   aAction: The action of the key (GLFW_PRESS, GLFW_RELEASE, GLFW_REPEAT)
        *   aMods: A bitfield describing which modifier keys were held down
        *   See http://www.glfw.org/docs/latest/group__mods.html for list of modifiers
        */
        static void m_KeyCallback(GLFWwindow * aWindow, int aKey, int aScanCode, int aAction, int aMods);
        /*
        *   GLFW Mouse button input callback method
        *   aWindow: The window that recieved the event
        *   aButton: The mouse button that was pressed or released
        *   aAction: The action (GLFW_PRESS , GLFW_RELEASE)
        *   aMods: A bitfield describing which modifier keys were held down
        *   See http://www.glfw.org/docs/latest/group__mods.html for list of modifiers
        */
        static void m_MouseButtonCallback(GLFWwindow * aWindow, int aButton, int aAction, int aMods);
        /*
        *   GLFW Mouse move input callback method
        *   aWindow: The window that recieved the event
        *   aXPosition: The mouse X Position
        *   aYPosition: The mouse Y Position
        */
        static void m_MouseMoveCallback(GLFWwindow * aWindow, double aXPosition, double aYPosition);
        /*
        *   GLFW Mouse scroll input callback method
        *   aWindow: The window that recieved the event
        *   aXAxis: The scroll offset along the x axis
        *   aYAxis: The scroll offset along the y axis
        */
        static void m_MouseScrollCallback(GLFWwindow * aWindow, double aXAxis, double aYAxis);


        //Member Variables
    public:

        //Member Variables
    private:
        //Handle to the window
        GLFWwindow * m_Window;
        //The window width
        int m_WindowWidth;
        //The window height
        int m_WindowHeight;
        //The window name
        String m_WindowTitle;
        //A boolean to control if the window is allocated or not
        bool m_Allocated;
    };

	/*
	//WINDOWS WINDOW
    class Window
    {
		//Methods
    public:
        Window();
        ~Window();

		void Create();
		//Methods
	private:
		static LRESULT CALLBACK WindowProc(HWND aWindowHandle, UINT aMsg, WPARAM aWParam, LPARAM aLParam);
		//Member Variables
    private:
		HWND m_WindowHandle;
		ATOM m_WindowClass;
		//Member Variables
	protected:
		//Window Dimensions
		int m_X;
		int m_Y;
		int m_Width;
		int m_Height;

		//Window Bits
		int m_Bits;


		//Mouse Positions
		int m_MouseX;
		int m_MouseY;
		int m_BoundedMouseX;
		int m_BoundedMouseY;

		//Window title
		std::string m_Title;
		

		//Window Style
		DWORD m_Style;
		DWORD m_FullscreenModeStyle;
		DWORD m_WindowedModeStyle;

		//Dimensions just before full screen enable
		int m_RestoreX;
		int m_RestoreY;
		int m_RestoreWidth;
		int m_RestoreHeight;
		

		//Dimensions of the whole screen
		int m_ScreenWidth;
		int m_ScreenHeight;
		int m_ScreenRefreshRate;

		//
		bool m_IsFullScreen;

		HDC m_DeviceContext;
		HGLRC m_OpenGLContext;


    };*/

    /*
	class Window
	{
	public:
		Window();
		Window(int aWidth, int aHeight, int aBits, bool aFullScreen = false);
		~Window();

		void swapBuffers();

	private:
		void registerWindowClass();
		void createContext();
		void initGL();
		void resizeGLScene();
		static LRESULT CALLBACK eventHandle(HWND aHandle, UINT aMessage, WPARAM aWParam, LPARAM aLParam);
		void processEvent(UINT aMessage, WPARAM aWParam, LPARAM aLParam);

		HWND m_Window;
		HDC m_DeviceContext;
		HGLRC m_OpenGLContext;

		int m_WindowWidth;
		int m_WindowHeight;
		std::string m_ClassName;
		bool m_FullScreen;

	};*/

}

#endif