#include "OL_Application.h"
#include "../Memory/OL_Memory.h"
#include "../../Game/OL_Game.h"
#include "../../Utilities/OL_Time.h"
#include "OL_Window.h"
#include <iostream>


#include "../../Utilities/OL_Utilities.h"
#include "../../Utilities/OL_UniqueNumberGenerator.h"


namespace OnLooker
{
        Application * Application::s_Instance = 0;
        Application * Application::instance()
        {
            if(s_Instance == 0)
            {
                s_Instance = Memory::instantiate<Application>();
            }
            return s_Instance;
        }
        
        void Application::destroy()
        {
            if(s_Instance != 0)
            {
                s_Instance = Memory::destroy<Application>(s_Instance);
            }
        }

        Application::Application()
        {
            m_Init = false;
            m_Game = 0;
              
        }

        Application::~Application()
        {
            if(m_Game != 0)
            {
                delete m_Game;
                m_Game = 0;
            }
        }

        bool Application::init()
        {
            if(m_Init == true)
            {
                return m_Init;
            }
            Time::m_StartTime = Window::getTime();
            Time::m_CurrentTime = Time::m_StartTime;
            Time::m_LastTime = Time::m_CurrentTime;
            Time::m_Delta = Time::m_CurrentTime - Time::m_LastTime;
            Time::m_FixedCurrentTime = Time::m_StartTime;
            Time::m_FixedLastTime = Time::m_FixedCurrentTime;
            Time::m_Delta = Time::m_FixedCurrentTime - Time::m_FixedLastTime;

            m_Game = new Game();
			m_Game->load();

            //Temp Code ***REMOVE***




            m_Init = true;

            return m_Init;
        }


        void Application::onIdle()
        {
            //Calculate delta
			Time::m_LastTime = Time::m_CurrentTime;
            Time::m_CurrentTime = Window::getTime();
            Time::m_Delta = Time::m_CurrentTime - Time::m_LastTime;
            //If initialization has not occured return.
            if(m_Init == false)
            {
                return;
            }

            if(m_Game != 0)
            {
                //Update
                m_Game->earlyUpdate();
                m_Game->update();
                m_Game->lateUpdate();
                //Physics
                float totalTime = 0.0f;
                float deltaTime = 0.0f;
                float timeStep = 0.016f;//Execute for as many frames as possible while remaining under 60 fps
                
                int currentFrame =  0;
                int totalFrames = 1; //Execute 1 frame max

                while(totalTime + deltaTime < timeStep)
                {
                    if(currentFrame >= totalFrames)
                    {
                        break;
                    }
                    
                    Time::m_FixedLastTime = Time::m_FixedCurrentTime;
                    Time::m_FixedCurrentTime = Window::getTime();
                    Time::m_FixedDelta = Time::m_FixedCurrentTime - Time::m_FixedLastTime;
                    //Fixed Update
                    m_Game->fixedUpdate();
                    //CollisionDetection
                    m_Game->collisionDetection();
                    

                    totalTime + Time::m_FixedDelta;
                    deltaTime = Time::m_FixedDelta;
                    currentFrame ++;
                }

                //Render && GUI
                m_Game->render();
                m_Game->gui();
            }
        }

        

        

}