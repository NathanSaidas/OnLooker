#include "OL_Console.h"
#include "OL_ConsoleMessage.h"
#include <iostream>
#include <stdio.h>
#include <stdarg.h>

#if WIN32
    #include <Windows.h>
    #include <io.h>
#endif

namespace OnLooker
{
    Console * Console::s_Instance = 0;
    Console * Console::getInstance()
    {
        if(s_Instance == 0)
        {
            s_Instance = new Console();
        }
        return s_Instance;
    }
    void Console::destroy()
    {
        if(s_Instance != 0)
        {
            delete s_Instance;
            s_Instance = 0;
        }
    }
    void Console::outputFormat(const char * aMessage, ...)
    {
        if(m_IsConsoleAllocated == false)
        {
            createConsole();
        }

        va_list arguments;
        va_start(arguments, aMessage);
        vprintf(aMessage, arguments);

        va_end(arguments);

    }
    void Console::output(int aValue)
    {
        if(m_IsConsoleAllocated == false)
        {
            createConsole();
        }
        printf("Console: %d \n",aValue);
    }
    void Console::output(float aValue)
    {
        if(m_IsConsoleAllocated == false)
        {
            createConsole();
        }
        printf("Console: %f \n",aValue);
    }
    void Console::output(double aValue)
    {
        if(m_IsConsoleAllocated == false)
        {
            createConsole();
        }
        printf("Console: %f \n",aValue);
    }
	void Console::output(std::string aMessage, bool aTrackOutputCount)
	{
		if(m_IsConsoleAllocated == false)
        {
            createConsole();
        }
		//If were tracking the input
		if(aTrackOutputCount == true)
		{
			//Check to see if the message exists and set the active message
			if(messageExists(aMessage) == true)
			{
				if(m_ActiveMessage != 0)
				{
					//output count
					if(aMessage == m_PreviousMessage)
					{
						clear();
						
					}
					m_ActiveMessage->addHit();
					std::cout << "Console: " << aMessage << " [Count(" << m_ActiveMessage->getHitCount() << ").\n";
					m_PreviousMessage = aMessage;
				}
				else
				{
					output(aMessage,false);
				}
			}
			else
			{
				//add message output count
				addMessage(aMessage);
				if(aMessage == m_PreviousMessage)
				{
					clear();
				}
				std::cout << "Console: " << aMessage << " [Count(" << m_ActiveMessage->getHitCount() << ").\n";
				m_PreviousMessage = aMessage;
			}
		}
		else
		{
			std::cout << "Console: " << aMessage << "\n";
		}
	}
	void Console::clear()
	{
#if WIN32
		system("cls");
#endif
	}
	void Console::addMessage(std::string aMessage)
	{
		if(aMessage == "")
		{
			return;
		}
		m_Messages.push_back(new ConsoleMessage(aMessage,m_MessagesTracked));
		m_ActiveMessage = m_Messages[m_Messages.size() -1];
		m_MessagesTracked++;
	}

	bool Console::messageExists(std::string aMessage)
	{
		//For all the messages
		for(int i = 0; i < m_Messages.size(); i++)
		{
			//If the message is not null and is the same as the parameter return true
			if(m_Messages[i] != 0)
			{
				if(m_Messages[i]->getMessage() == aMessage)
				{
					m_ActiveMessage = m_Messages[i];
					return true;
				}
			}
		}
		//exit out false
		return false;
	}

    Console::Console()
    {
        m_IsConsoleAllocated = false;
		m_MessagesTracked = 0;
    }
    Console::~Console()
    {

    }

    void Console::createConsole()
    {
#if WIN32
        m_IsConsoleAllocated = true;
        AllocConsole();
#if UNICODE
	SetConsoleTitle(L"Debug Console");
#else
	SetConsoleTitle("Debug Console");
#endif

    int hConHandle = _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE),0x4000);
    FILE * filePointer = _fdopen(hConHandle, "w");
    *stdout = *filePointer;
    setvbuf(stdout,NULL,_IONBF,0);
#endif
    }
    
}