#include "OL_Window.h"
#include "../../../Windows/OnLooker/OnLooker/Source/OL_Main.h"
#include "../../Libraries/OL_OpenGL.h"
namespace OnLooker
{
    Window::Window()
    {
        
        m_Window = 0;
        m_WindowWidth = 1024;
        m_WindowHeight = 768;
        m_WindowTitle = "Default Window";
        m_Allocated = false;
    }
    
    Window::Window(int aWidth, int aHeight, String aWindowName)
    {
        m_Window = 0;
        m_WindowWidth = aWidth;
        m_WindowHeight = aHeight;
        m_WindowTitle = aWindowName;
        m_Allocated = false;
    }
    Window::~Window()
    {
        if(m_Allocated == true)
        {
            destroy();
        }
    }
    void Window::onCreate(int aWidth, int aHeight, String aWindowName)
    {
        m_Window = 0;
        m_WindowWidth = aWidth;
        m_WindowHeight = aHeight;
        m_WindowTitle = aWindowName;
    }
       

    bool Window::createWindow()
    {
        //Set error callback
        glfwSetErrorCallback(m_ErrorCallback);

        //Initialize glfw
        if(!glfwInit())
        {
            //Error
            Debug::console->outputFormat("glfw failed to init \n");
            destroy();
            return false;
        }

        //Create the window
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        m_Window = glfwCreateWindow(m_WindowWidth,m_WindowHeight,m_WindowTitle.c_str(),0,0);

        if(!m_Window)
        {
            Debug::console->outputFormat("window failed to init \n");
            destroy();
            return false;
        }

        m_Allocated = true;


        //Set Callbacks & set this context 
        glfwMakeContextCurrent(m_Window);

        glfwSetKeyCallback(m_Window,m_KeyCallback);
        glfwSetMouseButtonCallback(m_Window,m_MouseButtonCallback);
        glfwSetCursorPosCallback(m_Window,m_MouseMoveCallback);
        glfwSetScrollCallback(m_Window,m_MouseScrollCallback);

        //Initialize glew
        if(glewInit() != GLEW_OK)
        {
            Debug::console->outputFormat("glew failed to init \n");
            destroy();
            return false;
        }
        return true;
    }
    void Window::destroy()
    {
        if(m_Allocated)
        {
            glfwDestroyWindow(m_Window);
        }
        glfwTerminate();
        m_Allocated = false;
    }
    

    GLFWwindow * Window::getWindowHandle()
    {
        return m_Window;
    }
    int Window::getWindowWidth()
    {
        return m_WindowWidth;
    }
    int Window::getWindowHeight()
    {
        return m_WindowHeight;
    }
    String Window::getWindowTitle()
    {
        return m_WindowTitle;
    }

    int Window::shouldWindowClose()
    {
        return glfwWindowShouldClose(m_Window);
    }

    void Window::m_ErrorCallback(int aError, const char * aDescription)
    {
        //TODO:Log the error using Debug.Log
        Debug::console->outputFormat("Error %i: %c \n",aError,aDescription);
    }
    
    void Window::m_KeyCallback(GLFWwindow * aWindow, int aKey, int aScanCode, int aAction, int aMods)
    {
        //TODO:Send input data to singleton input manager
        Input::instance()->handleKeyEvent(aKey,aAction);
    }
    void Window::m_MouseButtonCallback(GLFWwindow * aWindow, int aButton, int aAction, int aMods)
    {
        //TODO:Send input data to singleton input manager
        Input::instance()->handleMouseButtonEvent(aButton,aAction);
    }
    
    void Window::m_MouseMoveCallback(GLFWwindow * aWindow, double aXPosition, double aYPosition)
    {
        //TODO:Send input data to singleton input manager
        Input::instance()->handleMouseMove(aXPosition,aYPosition);
    }
    void Window::m_MouseScrollCallback(GLFWwindow * aWindow, double aXAxis, double aYAxis)
    {
        //TODO:Send input data to singleton input manager
        Input::instance()->handleMouseScroll(aXAxis,aYAxis);
    }

    double Window::getTime()
    {
        return glfwGetTime();
    }
    void Window::pollEvents()
    {
        glfwPollEvents();
    }
    void Window::swapBuffers()
    {
        glfwSwapBuffers(m_Window);
    }
    

	/*Window::Window()
	{
		m_X = 0;
		m_Y = 0;
		m_Width = 1024;
		m_Height = 768;

		m_Title = "OnLooker Engine";
		m_WindowedModeStyle = WS_CAPTION | WS_SYSMENU | WS_VISIBLE | WS_MINIMIZEBOX;  //default style
		m_FullscreenModeStyle = WS_POPUP;
		m_IsFullScreen = false;

		m_ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
		m_ScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	}
    Window::~Window()
	{
	}

	void Window::Create()
	{
		//Create the window class
		//Register Window Class
		if(m_WindowClass)
		{
			//return true;
		}
		else
		{
			WNDCLASS wc;
			wc.style				= CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
			wc.lpfnWndProc			= WindowProc;
			wc.cbClsExtra			= 0;
			wc.cbWndExtra			= 0;
			wc.hInstance			= Main::getInstance()->getInstanceHandle();
			wc.hIcon				= LoadIcon(NULL,IDI_APPLICATION);
			wc.hCursor				= LoadCursor(NULL, IDC_ARROW);
			wc.hbrBackground		= (HBRUSH)(COLOR_WINDOW + 1);
			wc.lpszMenuName			= NULL;
			wc.lpszClassName		= "OnLooker Engine";

			//register the window class
			m_WindowClass = RegisterClass(&wc);

		}

		//Setup Dev Mode
		if(m_IsFullScreen == true)
		{
			//Setup DEVMODE settings
			DEVMODE dmScreenSettings;
			memset(&dmScreenSettings, 0 , sizeof(dmScreenSettings));
			dmScreenSettings.dmSize = sizeof(dmScreenSettings);		
			dmScreenSettings.dmPelsWidth	= m_Width;									//Horizontal Screen Resolution
			dmScreenSettings.dmPelsHeight	= m_Height;									//Vertical Screen Resolution
			dmScreenSettings.dmBitsPerPel	= m_Bits;									//Color depth
			dmScreenSettings.dmDriverExtra	= 0;										//The device drigver does not use specific information
			dmScreenSettings.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL;	//Tell DEVMODE what fields we wish to override

			if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
			{
				//Throw an error 
				//And return
			}
			//Get Refresh Rate
			EnumDisplaySettings(0,ENUM_CURRENT_SETTINGS, &dmScreenSettings);
			m_ScreenRefreshRate = dmScreenSettings.dmDisplayFrequency;

		}

		if(m_IsFullScreen)
		{
			m_Style = m_FullscreenModeStyle;
		}
		else
		{
			m_Style = m_WindowedModeStyle;
		}

		RECT windowRect;
		windowRect.top = m_Y;
		windowRect.left = m_X;
		windowRect.right = m_X + m_Width;
		windowRect.bottom = m_Y + m_Height;

		//Set the window position and size
		AdjustWindowRect(&windowRect, m_Style, FALSE);

		//Create the window
		m_WindowHandle = CreateWindow(
			"OnLooker Engine",							//Class NAme
			m_Title.c_str(),							//Title Name
			m_Style,									//Style
			m_X,										//X Coordinate
			m_Y,										//Y Coordinate
			m_Width,									//Width
			m_Height,									//Height
			NULL,										//Handle to parent
			NULL,										//Handle to menu
			Main::getInstance()->getInstanceHandle(),	//Instance
			this);										//Creation Params
		
		PIXELFORMATDESCRIPTOR pfd;
		memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
		pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
		pfd.nVersion = 1;
		pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pfd.iPixelType = PFD_TYPE_RGBA;
		pfd.cColorBits = m_Bits;


		m_DeviceContext = GetDC(m_WindowHandle);
		//error check

		int pixelFormat = 0;

		pixelFormat = ChoosePixelFormat(m_DeviceContext, &pfd);
		//error check

		//error check
		SetPixelFormat(m_DeviceContext,pixelFormat,&pfd);
		

		m_OpenGLContext = wglCreateContext(m_DeviceContext);
		//error check

		wglMakeCurrent(m_DeviceContext,m_OpenGLContext);

		ShowWindow(m_WindowHandle,SW_SHOW);

		if(!m_WindowHandle)
		{
			//Give Error
			return;
		}
	
	}

	LRESULT CALLBACK Window::WindowProc(HWND aWindowHandle, UINT aMsg, WPARAM aWParam, LPARAM aLParam)
	{


		return 0;
	}*/
	/*Window::Window()
	{
	}
	Window::Window(int aWidth, int aHeight, int aBits, bool aFullScreen)
	{
        m_Window = 0;
        m_DeviceContext = 0;
        m_OpenGLContext = 0;
        m_FullScreen = aFullScreen;

        m_WindowWidth = aWidth;
        m_WindowHeight = aHeight;
        

        registerWindowClass();

        RECT windowRect;
        windowRect.top = windowRect.left = 0;
        windowRect.right = aWidth;
        windowRect.bottom = aHeight;


        DWORD extendedWindowStyle = 0;
        DWORD windowStyle = 0;

        if (m_FullScreen)
	    {
		    DEVMODE dmScreenSettings;
		    memset(&dmScreenSettings,0,sizeof(dmScreenSettings));	
		    dmScreenSettings.dmSize = sizeof(dmScreenSettings);		
		    dmScreenSettings.dmPelsWidth	= m_WindowWidth;			
            dmScreenSettings.dmPelsHeight	= m_WindowHeight;		
		    dmScreenSettings.dmBitsPerPel	= aBits;		
		    dmScreenSettings.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL;

		    // Change the display settings to fullscreen. On error, throw 
		    // an exception.
		    if(ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)                   //Check to see if we can change modes
            {
                if(MessageBox(0,"The requested fullscreen mode is not supported by \nyour video card. Use Windowed Mode Instead?","ERROR",MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
                {
                    m_FullScreen = false;                                                                           //If were not we give the option to switch to windowed
                }
                else
                {
                    //MessageBox(0,"Program Will Now Close.","ERROR 2",MB_OK|MB_ICONSTOP);                           //If the user selects no then we quit using an error message;
                }
            }
        }
        
        if(m_FullScreen)
        {
            extendedWindowStyle = WS_EX_APPWINDOW;                                                                  //Extended windows style
            windowStyle = WS_POPUP;
            ShowCursor(TRUE);
        }
        else
        {
            extendedWindowStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;                                               //Extended windows style
		    windowStyle = WS_CAPTION | WS_SYSMENU | WS_VISIBLE | WS_MINIMIZEBOX;                                    //Windows style
            ShowCursor(TRUE);
            //windowStyle=WS_OVERLAPPEDWINDOW; // resizeable window                                                 //This style would enable window resizing
        }

        // Adjust the window to the true requested size
	    AdjustWindowRectEx(&windowRect, windowStyle, FALSE, extendedWindowStyle);		
	    // Now create the main window
        if(!(m_Window = CreateWindowEx(extendedWindowStyle,                                                         //Create the window and set the window handle / Extended Style for window
                                            "OnLooker Engine",                                                      //Class Name
                                            "OnLooker Engine",                                                      //Window Title
                                            windowStyle | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,                        //Defined Window Style | Required Window Style | Required Window Style
                                            20,                                                                      //Window X Position
                                            20,                                                                      //Window Y Positoin
                                            windowRect.right - windowRect.left,                                     //Calculate Window Width
                                            windowRect.bottom - windowRect.top,                                     //Calculate Window Height
                                            0,                                                                      //No Parent Window
                                            0,                                                                      //No Menu
                                            GetModuleHandle(NULL),                                                  //Instance handle
                                            this)))
        {
            //error
        }


        createContext();
        initGL();
        ShowWindow(m_Window, SW_SHOW);

        resizeGLScene();

	}
	Window::~Window()
	{
        /*if(m_Texture)
        {
            delete[] m_Texture;
        }
	    if (m_FullScreen)
	    {
		    // Remove the full screen setting
		    ChangeDisplaySettings(NULL,0);
		    ShowCursor(TRUE);	
	    }

        if (m_OpenGLContext)
	    {
		    // Make the rendering context not current
		    wglMakeCurrent(NULL,NULL);
		    // Delete the OpenGL rendering context
            wglDeleteContext(m_OpenGLContext);
		    m_OpenGLContext = NULL;
	    }
        if (m_DeviceContext)
	    {
		    // Release the device context
            ReleaseDC(m_Window,m_DeviceContext);
            m_DeviceContext = NULL;
	    }

	    // Finally, destroy our main window and unregister the
	    // window class.
        DestroyWindow(m_Window);
        UnregisterClass(TEXT("OnLooker Engine"), GetModuleHandle(NULL));
	}

	void Window::swapBuffers()
	{
        SwapBuffers(m_DeviceContext);
	}
	void Window::registerWindowClass()
	{
        WNDCLASS windowClass;
    windowClass.style         = CS_OWNDC;
    windowClass.lpfnWndProc   = eventHandle;
    windowClass.cbClsExtra    = 0;
    windowClass.cbWndExtra    = 0;
    windowClass.hInstance     = GetModuleHandle(NULL);
    windowClass.hIcon         = NULL;
    windowClass.hCursor       = 0;
    windowClass.hbrBackground = 0;
    windowClass.lpszMenuName  = NULL;
    windowClass.lpszClassName = "OnLooker Engine";

    RegisterClass(&windowClass);
	}
	void Window::createContext()
	{
        // Describes the pixel format of the drawing surface
	    PIXELFORMATDESCRIPTOR pixelFormatDescriptor;
	    memset(&pixelFormatDescriptor, 0, sizeof(PIXELFORMATDESCRIPTOR));
	    pixelFormatDescriptor.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	    pixelFormatDescriptor.nVersion = 1;	// Version Number
	    pixelFormatDescriptor.dwFlags = PFD_DRAW_TO_WINDOW |	// Draws to a window
				      PFD_SUPPORT_OPENGL |	// The format must support OpenGL
				      PFD_DOUBLEBUFFER;		// Support for double buffering
	    pixelFormatDescriptor.iPixelType = PFD_TYPE_RGBA;		// Uses an RGBA pixel format
	    pixelFormatDescriptor.cColorBits = 32;				// 32 bits colors

	    if(!(m_DeviceContext = GetDC(m_Window)))                                                        //Create a window device context
        {

        }
    
        int pixelFormat = 0;                                                                                        //create a variable to store the pixelformat
        //get correct pixel format
        if(!(pixelFormat = ChoosePixelFormat(m_DeviceContext, &pixelFormatDescriptor)))                       //get the correct pixel format
        {

        }

        //set the new pixel format
        if(!(SetPixelFormat(m_DeviceContext,pixelFormat,&pixelFormatDescriptor)))                             //set the new pixel format
        {

        }
        //create opengl context
        if(!(m_OpenGLContext = wglCreateContext(m_DeviceContext)))                                            //create opengl context
        {

        }
        //activate context
        if(!wglMakeCurrent(m_DeviceContext,m_OpenGLContext))                                                  //Activate opengl context
        {

        }				
	}
	void Window::initGL()
	{
        // Enable 2D texturing
	glEnable(GL_TEXTURE_2D);
	// Choose a smooth shading model
    glShadeModel(GL_SMOOTH);
	// Set the clear color to black
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Enable the alpha test. This is needed 
	// to be able to have images with transparent 
	// parts.
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.0f);

    //glEnable(GL_BLEND);									//enable blending
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	
	}
	void Window::resizeGLScene()
	{
        // Sets the size of the OpenGL viewport
        glViewport(0,0,m_WindowWidth,m_WindowHeight);

	    // Select the projection stack and apply 
	    // an orthographic projection
	    glMatrixMode(GL_PROJECTION);
	    glLoadIdentity();
	    glOrtho(0.0,m_WindowWidth,m_WindowHeight,0.0,-1.0,1.0);
	    glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
	}
	LRESULT CALLBACK Window::eventHandle(HWND aHandle, UINT aMessage, WPARAM aWParam, LPARAM aLParam)
	{
        //When the program first starts one of the first messages is WM_NCCREATE
	    if (aMessage == WM_NCCREATE)
	    {
            // Get the creation parameters.
		    CREATESTRUCT* pCreateStruct = reinterpret_cast<CREATESTRUCT*>(aLParam);

            // Set as the "user data" parameter of the window
            SetWindowLongPtr(aHandle, GWLP_USERDATA, 
						     reinterpret_cast<long>(pCreateStruct->lpCreateParams));
	    }

        // Get the CMainWindow instance corresponding to the window handle
        Window * pWindow = reinterpret_cast<Window*>
		    (GetWindowLongPtr(aHandle, GWLP_USERDATA));
	    if (pWindow)
		    pWindow->processEvent(aMessage,aWParam,aLParam);

        return DefWindowProc(aHandle, aMessage, aWParam, aLParam);
	}
	void Window::processEvent(UINT aMessage, WPARAM aWParam, LPARAM aLParam)
	{
        int positionX;
        int positionY;
        switch (aMessage)
        {
            // Quit when we close the main window
            case WM_CLOSE :
                PostQuitMessage(0);
			    break;
		    case WM_SIZE:
		        resizeGLScene();
			    break;
            case WM_KEYDOWN :

                return;
            case WM_KEYUP :

                return;
            case WM_LBUTTONDOWN:

                return;
            case WM_RBUTTONDOWN:

                return;
            case WM_LBUTTONUP:

                return;
            case WM_RBUTTONUP:

                return;
            case WM_MOUSEMOVE:

                return;
        }
	}*/


}