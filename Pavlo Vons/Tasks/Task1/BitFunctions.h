/** 
 * @file	BitFunctions.h
 * @brief	Contain functions prototypes for working with bits
 *
 * @author	Pavlo Vons
 * @date	16 October 2012 
 */

#ifndef _BINFUNCTIONS_H_
#define _BINFUNCTIONS_H_

typedef unsigned long int ULI;
typedef unsigned int UI;

/**
  * @brief		This function replaces all neighboring group of two bits
  * @param		[in] Unsigned long integer number
  * @return		unsigned long int
  */
ULI ReplaceGroupOfBytes(ULI&); // task 12

/**
  * @brief		This function returns a count of 1 in a number
  * @param		[in] Unsigned long integer number
  * @return		unsigned long int
  */
ULI CountOf1(ULI&); // task 13

/**
  * @brief		This function returns integer number which satisfies a given equation
  * @param		[in] Unsigned long integer number
  * @return		unsigned int
  */
UI Log2X(ULI&); // task 14

/**
  * @brief		This function returns 1 if number is a power of two.
  * @param		[in] Unsigned long integer number
  * @return		char
  */
char IsPowerOfTwo(ULI&); // task 15

/**
  * @brief		This function create a number
  * @param		[in] Count of 1
  * @param		[in] Position in a number
  * @return		unsigned long int
  */
ULI CreateNumber(UI&, UI&); // task 16

#endif /* _BINFUNCTIONS_H_ */