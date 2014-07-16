#include "OL_Time.h"


//Unused

namespace OnLooker
{
    float Time::m_Delta = 0.0f;
    float Time::m_CurrentTime = 0.0f;
    float Time::m_LastTime = 0.0f;
    float Time::m_StartTime = 0.0f;
    float Time::m_FixedCurrentTime = 0.0f;
    float Time::m_FixedLastTime = 0.0f;
    float Time::m_FixedDelta = 0.0f;

    float Time::delta()
    {
        return m_Delta;
    }
    float Time::fixedDelta()
    {
        return m_FixedDelta;
    }
    float Time::startTime()
    {
        return m_StartTime;
    }
}
