/** 
 * @file	MyStaticLibrary.cpp
 * @brief	Contain methods for static library MyStaticLibrary
 *
 * @author	Pavlo Vons
 * @date	13 November 2012
 * 
 */

#include <iostream>
#include "MyStaticLibrary.h"

namespace MyStaticLibrary
{
	Stack::Stack()
	{
		indexOfLast = 0;
		try{
			stackElems = new UC[N];
		}
		catch(std::bad_alloc)
		{

		}
		stackElems[0] = '\0';
	}

	Stack::~Stack()
	{
		indexOfLast = 0;
		delete [] stackElems;
	}

	int Stack::PrintStack()
	{
		if(indexOfLast == 0)
			return 0;
		register int i = indexOfLast;
		while(i != 0)
		{
			--i;
			std::cout << "<" << *(stackElems+i) << "> ";
		}
		std::cout << "\n -> ";
		return 1;
	}

	int Stack::CleanStack()
	{
		if(indexOfLast == 0)
			return 0;
		else
		{
			indexOfLast = 0;
			stackElems[0] = '\0';
			return 1;
		}
	}

	int Stack::StackIsEmpty()
	{
		if(indexOfLast == 0)
		{
			return 1;
		}
		else if(indexOfLast == N)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}

	int Stack::PushElemInStack(UC c)
	{
		if(indexOfLast == N)
		{
			return 0;
		}
		else
		{
			stackElems[indexOfLast] = c;
			++indexOfLast;
			if(indexOfLast != N)
				stackElems[indexOfLast] = '\0';
			return 1;
		}
	}

	UC Stack::TopStack()
	{
		if(indexOfLast == 0)
		{
			return '\0';
		}
		else
		{
			return stackElems[indexOfLast - 1];
		}
	}

	UC Stack::PopElemFromStack()
	{
		if(indexOfLast == 0)
		{
			return '\0';
		}
		else
		{
			--indexOfLast;
			UC c = stackElems[indexOfLast];
			stackElems[indexOfLast] = '\0';
			return c;
		}
	}
}