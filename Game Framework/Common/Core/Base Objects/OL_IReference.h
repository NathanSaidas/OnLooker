#ifndef OL_I_REFERENCE_H
#define OL_I_REFERENCE_H
#include "OL_Object.h"

namespace OnLooker
{
	/*
	*   Class: IReference
	*   Base Class: Object
	*   Description: 
	*   Date Modified: 18/3/2014 by Nathan Hanlan
	*/
	class IReference : public Object
	{
	public:
		/*
		*   Function: IReference
		*   Return Type: Constructor
		*   Description: Constructs the IReference object
		*   Parameters: None
		*   Date Modified: 18/3/2014 by Nathan Hanlan
		*/
		IReference();
		/*
		*   Function: IReference
		*   Return Type: Destructor
		*   Description: Destroys the IReference object
		*   Parameters: None
		*   Date Modified: 18/3/2014 by Nathan Hanlan
		*/
		~IReference();

		/*
		*   Function: addReference
		*   Return Type: void
		*   Description: Increments the reference count to the object
		*   Parameters: None
		*   Date Modified: 18/3/2014 by Nathan Hanlan
		*/
		virtual void addReference();
		/*
		*   Function: removeReference
		*   Return Type: bool
		*   Description: Decrements the reference count
		*   Parameters: None
		*   Date Modified: 18/3/2014 by Nathan Hanlan
		*/
		virtual bool removeReference();
		/*
		*   Function: getReferenceCount
		*   Return Type: bool
		*   Description: returns the number of references this object has
		*   Parameters: None
		*   Date Modified: 18/3/2014 by Nathan Hanlan
		*/
		virtual int getReferenceCount(); 

	private:
		//A variable to hold the count for amount of references pointing to this object.
		int m_ReferenceCount;
	};
}

#endif