/** 
 * @file	MyDynamicLinkLibrary.h
 * @brief	Contain prototypes for dynamic link library MyDynamicLinkLibrary
 *
 * @author	Pavlo Vons
 * @date	13 November 2012 
 */

#ifndef _STACKDLL_H_
#define _STACKDLL_H_

#define N 10000

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

		 Stack();

		~Stack();

		/**
		* @brief    This function prints all elements of stack
		* @return	0 - if stack is empty
		* @return	1 - when printed all elements
		*/
		int PrintStack();

		/**
		* @brief    This function removed all elements of stack
		* @return	0 - if stack is empty
		* @return	1 - when removed all elements
		*/
		int CleanStack();

		/**
		* @brief    This function show is stack is empty
		* @return	1 - if stack is empty
		* @return	0 - if stack is not full
		* @return	-1 - if stack is full
		*/
		int StackIsEmpty();

		/**
		* @brief    This function show is stack is empty
		* @params	unsigned char - element which must be added to stack
		* @return	0 - if stack is full
		* @return	1 - if operation succesful
		*/
		int PushElemInStack(UC);

		/**
		* @brief    This function returns top element of stack
		* @return	'\0' - if stack is empty
		* @return	unsigned char - top element of stack
		*/
		UC TopStack();

		/**
		* @brief    This function removed top element of stack
		* @return	'\0' - if stack is empty
		* @return	Removed element of stack
		*/
		UC PopElemFromStack();
	};

#endif /* _STACKDLL_H_ */