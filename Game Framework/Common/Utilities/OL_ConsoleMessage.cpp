#include "OL_ConsoleMessage.h"

namespace OnLooker
{
	ConsoleMessage::ConsoleMessage()
	{
		m_HitCount = 0;
		m_ID = -1; //Invalid ID
	}
	ConsoleMessage::ConsoleMessage(std::string aMessage, int aID)
	{
		m_HitCount = 1;
		m_Message = aMessage;
		m_ID = aID;
	}
	ConsoleMessage::~ConsoleMessage()
	{

	}
	void ConsoleMessage::addHit()
	{
		m_HitCount ++;
	}
	int ConsoleMessage::getHitCount()
	{
		return m_HitCount;
	}
	int ConsoleMessage::getID()
	{
		return m_ID;
	}
	std::string ConsoleMessage::getMessage()
	{
		return m_Message;
	}
}