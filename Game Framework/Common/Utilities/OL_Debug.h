#ifndef OL_DEBUG_H
#define OL_DEBUG_H
/*
*   Filename: OL_Debug.h
*   Date Modified: 02/03/2014 by Nathan Hanlan
*   Comments:  v1.0.0 Added and Implemented class Debug
*/

namespace OnLooker
{
    class Console;
    /*
    *   Class: Debug
    *   Base Class: N/A
    *   Description: Debug offers utilities functions to help debug
    *   Debug - Output
    *   Debug - Log
    *   Date Modified: 02/03/2014 by Nathan Hanlan
    */
    class Debug
    {
    public:
        static Console * console;

        static void initialize();
        static void destroy();
    };

}

#endif