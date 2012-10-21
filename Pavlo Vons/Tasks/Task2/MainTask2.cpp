/** 
 * @file	MainTask2.cpp
 * @brief	
 *
 * @author	Pavlo Vons
 * @date	21 October 2012
 * 
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "PointFunctions.h"

using namespace std;

int main()
{
	int i;
	struct Point p[N], *p1, *p2;
	char s1[10], s2[10];

	//cout<<"Input points:\n";
	printf("Input points:\n");
	for(i = 0; i < N; i++)
		scanf("%d %d %s", &p[i].x, &p[i].y, p[i].color);
	
	Sort(p);

	//cout<<"Results after sorting:\n";
	printf("Results after sorting:\n");
	for(i = 0; i < N; i++)
		//cout<<p[i].x<<" "<<p[i].y<<" "p[i].color;
		printf("%d %d %s\n", p[i].x, p[i].y, p[i].color);

	p1 = &p[0];
	strcpy(s1, p[0].color);
	for(i = 1; i < N; i++)
		if(strcmp(s1, p[i].color) == 0 )
			p2 = &p[i];
		else
		{
			MaxDistance(p1, p2);
			p1 = &p[i];
			strcpy(s1, p[i].color);
			p2 = &p[i];
		}
	MaxDistance(p1, p2);
	return 0;
}
