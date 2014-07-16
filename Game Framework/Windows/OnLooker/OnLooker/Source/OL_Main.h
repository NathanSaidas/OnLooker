#ifndef OL_MAIN_H
#define OL_MAIN_H
/*
*   Filename: OL_Main.h
*   Date Modified: 25/02/2014 by Nathan Hanlan
*   Comments: v1.0.0 Initial Creation
*             - Added Main Class
*             - Added Include for the path to the OL_Common.h
*   v1.0.1    - Added variable m_Window;
*/

//Include the path to the common folder
#include "../../../../Common/OL_Common.h"





namespace OnLooker
{
    class Window;
    /*
    *   Class: Main
    *   Base Class: N/A
    *   Description: The entry point of the program.
    *   Date Modified: 25/02/2014 by Nathan Hanlan
    */
    class Main : public Object
    {
        //Methods
    public:
        /*
        *   Function: getInstance
        *   Return Type: static Main *
        *   Description: Singleton design pattern used to create the instance of the class and return it.
        *   Parameters: N/A
        *   Date Modified: 25/02/2014 by Nathan Hanlan
        */
        static Main * getInstance();
        /*
        *   Function: destroy
        *   Return Type: static void
        *   Description: Singleton design pattern used to free the instance of the class.
        *   Parameters: N/A
        *   Date Modified: 25/02/2014 by Nathan Hanlan
        */
        static void destroy();

        /*
        *   Function: run
        *   Return Type: int
        *   Description: Call upon this method to start the program
        *   Parameters: N/A
        *   Date Modified: 25/02/2014 by Nathan Hanlan
        */
        int run();


		

        //Methods
    private:
        /*
        *   Function: Main
        *   Return Type: Constructor - Default
        *   Description: Initialized member variables to null.
        *   Parameters: N/A
        *   Date Modified: 25/02/2014 by Nathan Hanlan
        */
        Main();
        /*
        *   Function: Main
        *   Return Type: Destructor
        *   Description: Deallocates the instance of this class.
        *   Parameters: N/A
        *   Date Modified: 25/02/2014 by Nathan Hanlan
        */
        ~Main();
        

        void onExit();


        //Member Variables
    public:

        //Member Variables
    private:
        //The instance of the class.
        static Main * s_Instance;
        Window * m_Window;


        friend PoolAllocator;
    };
}


#endif