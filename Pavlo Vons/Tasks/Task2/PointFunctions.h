/** 
 * @file	PointFunctions.h
 * @brief	Contain functions prototypes for working with points
 *
 * @author	Pavlo Vons
 * @date	20 October 2012 
 */

#ifndef _POINTFUNCTIONS_H_
#define _POINTFUNCTIONS_H_

const int N=6;

struct Point
{
	int x;
	int y;
	char color[10];
};

/**
  * @brief		This function for checking entered data
  * @param		[in] pointer struct Point pointer
  * @return		void
  */
void Input(struct Point *);

/**
  * @brief		This function sorts array of points with color
  * @param		[in] pointer struct Point pointer
  * @return		void
  */
void Sort(struct Point *);

/**
  * @brief		This function looks for maximum distance betwwen two points with same colors
  * @param		[in] pointer struct Point pointer - begin of array
  * @param		[in] pointer struct Point pointer - end of array
  * @return		void
  */
void MaxDistance(struct Point *, struct Point *);

/**
  * @brief		This function calculates a distance between two points
  * @param		[in] struct Point - first point
  * @param		[in] struct Point - second point
  * @return		double
  */
double Distance(struct Point&, struct Point&);

#endif /* _POINTFUNCTIONS_H_ */