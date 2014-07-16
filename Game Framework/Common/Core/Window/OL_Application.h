#ifndef OL_APPLICATION_H
#define OL_APPLICATION_H

#include "../Base Objects/OL_Object.h"

namespace OnLooker
{
    class Game;
    class PoolAllocator;
    /*
    *   Class: Application
    *   Base Class: N/A
    *   Description: The application is what will handle a large portion of the game engine data
    *   Date Modified: 25/02/2014 by Nathan Hanlan
    */
    class Application : public Object
    {
        //Methods
    public:
        /*
        *   Function: getInstance
        *   Return Type: static Application *
        *   Description: Singleton design pattern used to create the instance of the class and return it.
        *   Parameters: N/A
        *   Date Modified: 25/02/2014 by Nathan Hanlan
        */
        static Application * instance();
        /*
        *   Function: destroy
        *   Return Type: static void
        *   Description: Singleton design pattern used to free the instance of the class.
        *   Parameters: N/A
        *   Date Modified: 25/02/2014 by Nathan Hanlan
        */
        static void destroy();


        /*
        *   Function: init
        *   Return Type: void
        *   Description: This method initializes application();
        *   Parameters: N/A
        *   Date Modified: 25/02/2014 by Nathan Hanlan
        */
        bool init();
        /*
        *   Function: onIdle
        *   Return Type: void
        *   Description: This is the looping part of the application game logic goes in here
        *   Parameters: N/A
        *   Date Modified: 25/02/2014 by Nathan Hanlan
        */
        void onIdle();

        


        //Methods
    private:
        /*
        *   Function: Application
        *   Return Type: Constructor - Default
        *   Description: Initialized member variables to null.
        *   Parameters: N/A
        *   Date Modified: 25/02/2014 by Nathan Hanlan
        */
        Application();
        /*
        *   Function: Application
        *   Return Type: Destructor
        *   Description: Deallocates the instance of this class.
        *   Parameters: N/A
        *   Date Modified: 25/02/2014 by Nathan Hanlan
        */
        ~Application();

        //Member Variables
    public:

        
        //Member Variables
    private:
        //If init went well this will be true
        bool m_Init;

		

        static Application * s_Instance;
        Game * m_Game;
        friend PoolAllocator;
    };

}

#endif