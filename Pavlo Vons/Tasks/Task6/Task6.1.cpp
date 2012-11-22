/** 
 * @file	Task6.1.cpp
 * @brief	Defines the entry point for the console application.
 *
 * @author	Pavlo Vons
 * @date	19 November 2012
 * 
 */

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Check.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Input string:";
	string s;
	cin>>s;
	char *ps=&s[0];
	if( StartCheck(ps) )
		cout << "String is correct!";
	else
		cout << "String is incorrect!";
	return 0;
}

