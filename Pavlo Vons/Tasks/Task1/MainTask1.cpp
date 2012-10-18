/** 
 * @file	main.cpp
 * @brief	
 *
 * @author	Pavlo Vons
 * @date	16 October 2012
 * 
 */

#include <iostream>

using namespace std;

#include "BitFunctions.h"

int main()
{
	ULI num1, num2;
	char *tmpbuf = new char[sizeof(ULI) * 8];
	UI n, p;

	//====================12 excercises=======================
	cout<<"Enter number: ";
	cin>>num1;
	itoa(num1, tmpbuf, 2);
	cout<<"Entered value:   ";
	cout<<"DEC: "<<num1<<" BIN:"<<tmpbuf<<"\n";
	num2=ReplaceGroupOfBytes(num1);
	itoa(num2, tmpbuf, 2);
	cout<<"Resulting value: ";
	cout<<"DEC: "<<num2<<" BIN:"<<tmpbuf<<"\n";
	cout<<"===============================================\n";
	//========================================================

	//====================13 excercises=======================
	cout<<"Enter number: ";
	cin>>num1;
	itoa(num1, tmpbuf, 2);
	cout<<"Entered value:   ";
	cout<<"DEC: "<<num1<<" BIN:"<<tmpbuf<<"\n";
	num2=CountOf1(num1);
	cout<<"Resulting value: "<<num2<<"\n";
	cout<<"===============================================\n";
	//========================================================
	
	//====================14 excercises=======================
	cout<<"Enter number: ";
	cin>>num1;
	itoa(num1, tmpbuf, 2);
	cout<<"Entered value:   ";
	cout<<"DEC: "<<num1<<" BIN:"<<tmpbuf<<"\n";
	num2=Log2X(num1);
	cout<<"Resulting value: "<<num2<<"\n";
	cout<<"===============================================\n";
	//========================================================

	//====================15 excercises=======================
	cout<<"Enter number: ";
	cin>>num1;
	itoa(num1, tmpbuf, 2);
	cout<<"Entered value:   ";
	cout<<"DEC: "<<num1<<" BIN:"<<tmpbuf<<"\n";
	if(IsPowerOfTwo(num1))
		cout<<"Resulting value: "<<"This number is a power of two.\n";
	else
		cout<<"Resulting value: "<<"This number isn't a power of two.\n";
	cout<<"===============================================\n";
	//========================================================

	//====================16 excercises=======================
	cout<<"Enter n: ";
	cin>>n;
	cout<<"Enter p: ";
	cin>>p;
	num2=CreateNumber(n, p);
	itoa(num2, tmpbuf, 2);
	cout<<"DEC: "<<num2<<" BIN:"<<tmpbuf<<"\n";
	cout<<"===============================================\n";
	//========================================================
	delete [] tmpbuf;
	return 0;
}