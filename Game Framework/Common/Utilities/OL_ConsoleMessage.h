#ifndef OL_CONSOLE_MESSAGE_H
#define OL_CONSOLE_MESSAGE_H

#include <string>
/*
*   Filename: OL_ConsoleMessage.h
*   Date Modified: 04/03/2014 by Nathan Hanlan
*   Comments: v1.0.0 Added and Implemented class ConsoleMessage
*/

namespace OnLooker
{
	/*
    *   Class: ConsoleMessage
    *   Base Class: N/A
    *   Description: The purpose of this class is to store a message for the console
    *   and keep a count of how many times the message has occured. Messages are created
	*	when the an instance of the object is instantiated.
    *   Date Modified: 04/03/2014 by Nathan Hanlan
    */
	class ConsoleMessage
	{
	public:
		/*
        *   Function: ConsoleMessage
        *   Return Type: constructor
        *   Description: The default constructor of console message, avoid the use of it
        *   Parameters: @parameter
        *   Date Modified: 04/03/2014 by Nathan Hanlan
        */
		ConsoleMessage();
		/*
        *   Function: ConsoleMessage
        *   Return Type: constructor
        *   Description: The constructor which sets values, use this to set the message / id value
        *   Parameters: @parameter aMessage - The value m_Message will be
		*	@parameter aID - The value m_ID will be
        *   Date Modified: 04/03/2014 by Nathan Hanlan
        */
		ConsoleMessage(std::string aMessage, int aID);
		/*
        *   Function: ConsoleMessage
        *   Return Type: destructor
        *   Description: Destroys the object
        *   Parameters: @parameter
        *   Date Modified: 04/03/2014 by Nathan Hanlan
        */
		~ConsoleMessage();

		/*
        *   Function: addHit
        *   Return Type: void
        *   Description: Adds one to the hit count
        *   Parameters: @parameter
        *   Date Modified: 04/03/2014 by Nathan Hanlan
        */
		void addHit();
		/*
        *   Function: getHitCount
        *   Return Type: int
        *   Description: returns m_HitCount
        *   Parameters: @parameter
        *   Date Modified: 04/03/2014 by Nathan Hanlan
        */
		int getHitCount();
		/*
        *   Function: getID
        *   Return Type: int
        *   Description: returns m_ID;
		*	-1 represents an invalid ID
        *   Parameters: @parameter
        *   Date Modified: 04/03/2014 by Nathan Hanlan
        */
		int getID();
		/*
        *   Function: getMessage
        *   Return Type: std::string
        *   Description: returns the m_Message
        *   Parameters: @parameter
        *   Date Modified: 04/03/2014 by Nathan Hanlan
        */
		std::string getMessage();

	private:
		//The Message
		std::string m_Message;
		//The ID
		int m_ID;
		//The hit count
		int m_HitCount; 
	};
}

#endif