#ifndef OL_STRING_H
#define OL_STRING_H

#include "OL_Object.h"


namespace OnLooker
{
    /*
    CALLING CONVENTIONS
    __cdecl is the default calling convention for C and C++ programs. The advantage of this calling convetion is that 
    it allows functions with a variable number of arguments to be used. The disadvantage is that it creates larger executables.

    __stdcall is used to call Win32 API functions. It does not allow functions to have a variable number of arguments.

    __fastcall attempts to put arguments in registers, rather than on the stack, thus making function calls faster.

    __thiscall calling convention is the default calling convention used by C++ member functions that do not use variable arguments.
   

    */

    //A very rare type that is not apart of the Reflection system.

    class String : public Object
    {
    public:
        String(String & aString);
        String(const char * aString);
        String(char aString[]);
        String();
        ~String();
        //Setters
        void set(const char * aString);
        void set(String & aString);
        void operator= (const char * rhs);
        void operator= (String & rhs);
        

        //Length
        inline const int & __stdcall length()
        {
            return m_Length;
        }
        inline const int & __stdcall calcLength() // More accurate
        {
            return stringLength(m_Characters);
        }
        bool operator> (const char * rhs);
        bool operator> (String & rhs);
        bool operator> (int & rhs);
        bool operator< (const char * rhs);
        bool operator< (String & rhs);
        bool operator< (int & rhs);
        bool operator>= (const char * rhs);
        bool operator>= (String & rhs);
        bool operator>= (int & rhs);
        bool operator<= (const char * rhs);
        bool operator<= (String & rhs);
        bool operator<= (int & rhs);
        //Append
        void append(String & aString);
        void append(const char * aString);
        String operator+ (String & rhs);
        void operator+= (String & rhs);
        String operator+ (const char * rhs);
        void operator+= (const char * rhs);
        //Compare (Equals / Difference) (Contains exact match)
        bool equals(const char * aString);
        bool equals(String & aString);
        bool operator== (const char * rhs);
        bool operator== (String & rhs);
        bool operator!= (const char * rhs);
        bool operator!= (String & rhs);
        //SubString
        void subString(String & aSubString,int aEnd); //assume start as 0
        void subString(String & aSubString,int aBegin, int aEnd);
        //Accessor
        inline const char * __stdcall c_str()
        {
            return m_Characters;
        }
        char at(const int aIndex);
        char operator[] (const int aIndex);

        static String empty();

    protected:
        virtual Reflection::Type getType();
        virtual Reflection::Type baseType();
        virtual Reflection::Type * instanceOf(int & aCount);
    private:
        //Helpers
        int getLength();
        char * getString();
        char getCharacterAtIndex(int aIndex);

        void setString(const char * aString);
        void setString(String & aString);

        void appendChar(char aChar);
        void appendString(const char * aString);
        void appendString(String & aString);

        bool compareString(const char * aString);
        bool compareString(String & aString);

        int stringLength(const char * aString);
        int stringLength(String & aString);

        //Allocation
        void resize(int newSize); //bad dont use
        char * allocString(int aSize);
        void deallocString(char * aString);
        //For faster substring only
        void allocBuffer(int aSize);
        void unsafeInsert(int aLocation, char aCharacter);

        //Members
        int m_Length;
        char * m_Characters;
    };
}

#endif