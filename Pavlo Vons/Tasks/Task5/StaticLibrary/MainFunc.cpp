/** 
 * @file	MainFunc.cpp
 * @brief	Contain interface for main function
 *
 * @author	Pavlo Vons
 * @date	13 November 2012
 * 
 */

#include "stdafx.h"
#include <iostream>

#include "MainFunc.h"

using namespace std;
using namespace MyStaticLibrary;

int MainFunc()
{
	std::cout << "                                                                                "
			<< "   00000000    0000000000000       0000          00000000       0000    000000  "
			<< " 000000000000  0000000000000      000000        00000000000     0000  000000    "
			<< " 000    0000       0000           0000000      00000   0000     0000 000000     "
			<< " 0000              0000          00000000      00000   0000     0000000000      "
			<< "  000000000        0000          000000000     0000             000000000       "
			<< "    00000000       0000         0000 00000     0000             000000000       "
			<< "       000000      0000        0000   00000    0000             0000000000      "
			<< " 0000    0000      0000        0000000000000   00000   0000     0000  00000     "
			<< " 0000    0000      0000       00000000000000   00000   0000     0000   00000    "
			<< " 00000000000       0000      00000    0000000   00000000000     0000    00000   "
			<< "    0000000        0000     0000       0000000    0000000       0000     00000  "
			<< "                                                                                ";
	UC c = '1';
	cout <<"This program working with stack which may be contained " << N << " elements\n\n";
	cout <<"Main menu. Please choose what operation do you want to be completed:\n"
		 <<"1-Show content of stack.\n"
		 <<"2-Clean content of stack.\n"
		 <<"3-Push element in stack.\n"
		 <<"4-Pop element in stack.\n"
		 <<"5-Top element in stack.\n"
		 <<"6-Fullness of stack.\n"
		 <<"7-Show main menu.\n"
		 <<"8-About.\n"
		 <<"0-Exit.\n"
		 <<" -> ";
	Stack s;
	while(c != '0')
	{
		c = _getch();
		cout << (char)c << endl;
		UC ct;
		switch(c)
		{
			case '1':
				if( !s.PrintStack( ) )
					cout << "Stack is empty.\n -> ";
				break;
			case '2':
				if( s.CleanStack( ) )
					cout << "Operation completed.\n -> ";
				else
					cout << "Stack was already empty.\n -> ";
				break;
			case '3':
				cout << "Enter symbol:\n -> ";
				ct = _getch();
				cout << ct << "\n";
				if( !s.PushElemInStack(ct) )
					cout << "Stack is full.\n -> ";
				else
					cout << "Operation completed.\n -> ";
				break;
			case '4':
				ct = s.PopElemFromStack();
				if(ct == '\0')
					cout << "Nothing to remove. Stack was already empty.\n -> ";
				else
					cout << "Operation completed. Removed symbol: \'" << ct << "\'.\n -> ";
				break;
			case '5':
				ct = s.TopStack();
				if(ct == '\0')
					cout << "Stack is empty.\n -> ";
				else
					cout << "Top of the stack: \'" << ct << "\'.\n -> ";
				break;
			case '6':
				if( s.StackIsEmpty() == 1 )
					cout << "Stack is empty.\n -> ";
				else if( s.StackIsEmpty() == -1 )
					cout << "Stack is full.\n -> ";
				else
					cout << "Stack is not full.\n -> ";
				break;
			case '7':
					cout << "Main menu. Please choose what operation do you want to be completed:\n"
						<< "1-Show content of stack.\n"
						<< "2-Clean content of stack.\n"
						<< "3-Push element in stack.\n"
						<< "4-Pop element in stack.\n"
						<< "5-Top element in stack.\n"
						<< "6-Fullness of stack.\n"
						<< "7-Show main menu.\n"
						<< "8-About.\n"
						<< "0-Exit.\n"
						<< " -> ";
				break;
			case '8':
				cout << "GlobalLogic Base Camp. Task 5.\n -> ";
				break;
			case '0':
				cout << "Thank you for choosing our application.\n";
				_getch();
				return 0;
			default:
				cout << "Input error. Try again.\n -> ";
				break;
		}
	}	
	return 0;
}