/** 
 * @file	BitFunctions.cpp
 * @brief	Contain functions for working with bits
 *
 * @author	Pavlo Vons
 * @date	16 October 2012
 * 
 */

#include <cmath>

#include "BitFunctions.h"

ULI ReplaceGroupOfBytes(ULI& num) // task 12
{
	return ( (num >> 2) & 0x33333333 ) + ( (num << 2) & 0xCCCCCCCC );
}

ULI CountOf1(ULI& num) // task 13
{
	ULI tmpnum;
	tmpnum = num;
	tmpnum = (tmpnum & 0x55555555) + ( (tmpnum >> 1) & 0x55555555 );
	tmpnum = (tmpnum & 0x33333333) + ( (tmpnum >> 2) & 0x33333333 );
	tmpnum = (tmpnum & 0x0f0f0f0f) + ( (tmpnum >> 4) & 0x0f0f0f0f );
	tmpnum = (tmpnum & 0x00ff00ff) + ( (tmpnum >> 8) & 0x00ff00ff );
	tmpnum = (tmpnum & 0x0000ffff) + ( (tmpnum >> 16) & 0x0000ffff );
	return tmpnum;
}

UI Log2X(ULI& num) // task 14
{
	ULI tmpnum = 1;
	UI k=0;
	while(tmpnum < num)
	{
		tmpnum <<= 1;
		++k;
	}
	--k;
	return k;
}

char IsPowerOfTwo(ULI& num) // task 15
{
	return !(num & (num-1) );
}

ULI CreateNumber(UI& n, UI& p) // task 16
{
	return ( (1<<n) - 1 ) << p;
}