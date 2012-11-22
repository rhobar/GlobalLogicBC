/** 
 * @file	Check.cpp
 * @brief	Contain interface for main file
 *
 * @author	Pavlo Vons
 * @date	19 November 2012
 * 
 */
#include "stdafx.h"
#include <iostream>
#include "Check.h"
#include "Stack.h"

using namespace std;

#define MAX_STR 1024

int StartCheck(char *str)
{
	Stack s;
	register int i = -1;

	do
	{
		i++;
		switch(*(str+i) )
		{
		case '{':
			s.PushElemInStack('{');
			break;
		case '[':
			s.PushElemInStack('[');
			break;
		case '(':
			s.PushElemInStack('(');
			break;
		case '}':
			if(s.TopStack()=='{')
				s.PopElemFromStack();
			else
				return 0;
			break;
		case ']':
			if(s.TopStack()=='[')
				s.PopElemFromStack();
			else
				return 0;
			break;
		case ')':
			if(s.TopStack()=='(')
				s.PopElemFromStack();
			else
				return 0;
			break;
		default:
			break;
		}
	}
	while(*(str + i) != '\0');
	if(s.StackIsEmpty() != 1)
		return 0;
	return 1;
}