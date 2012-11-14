/** 
 * @file	MyDynamicLinkLibrary.h
 * @brief	Contain prototypes for dynamic link library MyDynamicLinkLibrary
 *
 * @author	Pavlo Vons
 * @date	13 November 2012 
 */

#ifndef _MYDYNAMICLINKLIBRARY_H_
#define _MYDYNAMICLINKLIBRARY_H_

#define N 10

namespace MyDynamicLinkLibrary
{
	typedef unsigned char UC;
	typedef unsigned char UI;

/**
 * @class	[Mandatory] Stack
 * @brief	[Mandatory] Class performs operation with stack
 *
 * @remark	[Optional] Detailed description
 *
 * @see	[Optional] Related information
 *
 */

	class Stack
	{

		UC * stackElems;

		UI indexOfLast;
	public:

		__declspec(dllexport) Stack();

		__declspec(dllexport) ~Stack();

		/**
		* @brief    This function prints all elements of stack
		* @return	0 - if stack is empty
		* @return	1 - when printed all elements
		*/
		__declspec(dllexport) int PrintStack();

		/**
		* @brief    This function removed all elements of stack
		* @return	0 - if stack is empty
		* @return	1 - when removed all elements
		*/
		__declspec(dllexport) int CleanStack();

		/**
		* @brief    This function show is stack is empty
		* @return	1 - if stack is empty
		* @return	0 - if stack is not full
		* @return	-1 - if stack is full
		*/
		__declspec(dllexport) int StackIsEmpty();

		/**
		* @brief    This function show is stack is empty
		* @params	unsigned char - element which must be added to stack
		* @return	0 - if stack is full
		* @return	1 - if operation succesful
		*/
		__declspec(dllexport) int PushElemInStack(UC);

		/**
		* @brief    This function returns top element of stack
		* @return	'\0' - if stack is empty
		* @return	unsigned char - top element of stack
		*/
		__declspec(dllexport) UC TopStack();

		/**
		* @brief    This function removed top element of stack
		* @return	'\0' - if stack is empty
		* @return	Removed element of stack
		*/
		__declspec(dllexport) UC PopElemFromStack();
	};
}

#endif /* _MYDYNAMICLINKLIBRARY_H_ */