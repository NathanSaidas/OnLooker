#include "OL_Main.h"
#include "../../../../Common/Libraries/OL_OpenGL.h"
#include <iostream>

//#include "../../../../Common/Core/OL_Core.h"


/*
*   Filename: OL_Main.cpp
*   Date Modified: 25/02/2014 by Nathan Hanlan
*   Comments: v1.0.0 Initial Creation
*             - Implemented Main Class
*             - Wrote entry point.
*             - Implemented game loop and delta time calculation
*/



namespace OnLooker
{
        
        void onInit();
        void onDestroy();

        Main * Main::s_Instance = 0;
        Main * Main::getInstance()
        {
            if(s_Instance == 0)
            {
                s_Instance = Memory::instantiate<Main>();//new Main();
            }
            return s_Instance;
        }

        void Main::destroy()
        {
            if(s_Instance != 0)
            {
                //delete s_Instance;
                //s_Instance = 0;
                s_Instance = Memory::destroy<Main>(s_Instance);
            }
        }

        Main::Main()
        {
            m_Window = 0;
            
        }
        Main::~Main()
        {
            //onExit();
        }

        int Main::run()
        {
            //Create Window
            m_Window = Memory::instantiate<Window>();
            m_Window->onCreate(1024,768,"OnLooker v3.0");
            if(m_Window->createWindow() == false)
            {
                Debug::console->outputFormat("Failure to create window \n");
                onExit();
                return -1;
            }
			//Renderer setup
            Renderer::instance()->initialize(m_Window->getWindowWidth(),m_Window->getWindowHeight());
            if(Application::instance()->init() != true)
            {
                Debug::console->outputFormat("Failure to initialize Application \n");
                onExit();
                return -1;
            }
            ////Setup Time Variables pre loop
            

            if(Renderer::instance()->isReady() != true)
            {
                Debug::console->outputFormat("Failure to initialize Renderer \n");
                onExit();
                return -1;
            }

            onLookerInit();

            //Game Loop Here
            //TODO: Implement game update and render calls
            while(!m_Window->shouldWindowClose())
            {
            
                
                //Clear 
                Renderer::instance()->clear();
                //Game Update/Render
                Application::instance()->onIdle(); 
            
                //Check for Errors
                Renderer::instance()->checkForErrors();
                //Update window
                Input::instance()->handleStates();
                m_Window->swapBuffers();
                m_Window->pollEvents();
            }

            onExit();
            return 0;
        }
        

        //This function gets called before run is left
        void Main::onExit()
        {
            
            Application::destroy();
            Renderer::destroy();
            m_Window = Memory::destroy<Window>(m_Window);
            
            //if(m_Window != 0)
            //{
            //    m_Window->destroy();
            //    delete m_Window;
            //    m_Window = 0;
            //}


            Debug::destroy();
            FilePath::destroy();
        }

        
        void onInit()
        {
            MemoryManager::instance();
            Input::instance();
        }
        void onDestroy()
        {
            Input::destroy();
            MemoryManager::destroy();
        }
        

}


int main()
{
    OnLooker::onInit();
    int mainRunCode = OnLooker::Main::getInstance()->run();
    OnLooker::Main::destroy();
    OnLooker::onDestroy();

    return mainRunCode;
}