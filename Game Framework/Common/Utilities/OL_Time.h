#ifndef OL_TIME_H
#define OL_TIME_H
/*
*   Filename: OL_Time.h
*   Date Modified: 02/03/2014 by Nathan Hanlan
*   Comments: v1.0.0 Added and Implemented class Time
*/


namespace OnLooker
{
    class Main;
    class Application;
    /*
    *   Class: Time
    *   Base Class: N/A
    *   Description: Holds static data for the applications delta time
    *   Date Modified: 02/03/2014 by Nathan Hanlan
    */

    class Time
    {
    public:
        //The time between frames
        static float delta();
        static float fixedDelta();
        static float startTime();
    private:
        static float m_Delta;
        static float m_CurrentTime;
        static float m_LastTime;

        static float m_FixedDelta;
        static float m_FixedCurrentTime;
        static float m_FixedLastTime;

        static float m_StartTime;



        friend Application;
        friend Main;
    };

};

#endif