/** 
 * @file	PointFunctions.cpp
 * @brief	Contain functions for working with bits
 *
 * @author	Pavlo Vons
 * @date	21 October 2012
 * 
 */

#include <string.h>
#include <iostream>
#include <cmath>
#include "PointFunctions.h"

using namespace std;

void Sort(struct Point *p)
{
	int i, j;
	struct Point y;
	char str1[5], str2[5], s1[20], s2[20];
	for(i = N - 1; i > 0; i--)
		for(j = 0; j < i; j++)
		{ 
			strcpy(s1, (p+j)->color);
			strcpy(s2, (p+j+1)->color);
			if(strcmp(s1, s2) > 0 )
			{ 
				y = *(p+j);
				*(p+j) = *(p+j+1);
				*(p+j+1) = y;
			}
		}
	return;
}

void MaxDistance(struct Point *p1, struct Point *p2)
{
	struct Point *temp1 = p1, *temp2 = p1, *temp3, *temp4;
	double maxdist = -1;

	while(temp1 != p2)
	{		
		while(temp2 != p2)
		{
			++temp2;
			if(maxdist < Distance(*temp1, *temp2))
			{
				maxdist = Distance(*temp1, *temp2);
				temp3 = temp1;
				temp4 = temp2;
			}

		}
		++temp1;
		temp2 = temp1;
	}

	//printf("Maximum distance is %d between point (%i,%i) and (%i,%i) with color %s.",
	//	&maxdist, &(temp3->x), &(temp3->y), &(temp4->x), &(temp4->y), p1->color);
	cout<<"Maximum distance is "<< maxdist <<" between point ("<<temp3->x<<","<<temp3->y
		<<") and ("<<temp4->x<<","<<temp4->y<<") with color "<<p1->color<<".\n";
}

double Distance( struct Point& a , struct Point& b)
{
	return sqrt( (double) ( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) ) );
}