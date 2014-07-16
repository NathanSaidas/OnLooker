#include "OL_IReference.h"

namespace OnLooker
{

	IReference::IReference() : Object()
	{
	}
	IReference::~IReference()
	{
	}

	void IReference::addReference()
	{
		m_ReferenceCount ++;
	}
	bool IReference::removeReference()
	{
		if(--m_ReferenceCount <= 0)
		{
			m_ReferenceCount = 0;
			return false;
		}
		return true;
	}
	int IReference::getReferenceCount()
	{
		return m_ReferenceCount;
	}
}