/** 
 * @file	MatrixOpeartions.cpp
 * @brief	Contain functions for working with matrix
 *
 * @author	Pavlo Vons
 * @date	26 October 2012
 * 
 */

#include "stdafx.h"
#include <stdlib.h>
#include "MatrixOperations.h"

unsigned int ModifyMatrix (double **matrix)
{
	unsigned int i, j, deletedRows = 0;
	double minElem;
	for(i = 0; i < MATRIX_ROWS; i++)
	{
		if(i == (MATRIX_ROWS - deletedRows) )
		{
			return deletedRows;
		}
		minElem = matrix[i][0];
		for(j = 1; j < MATRIX_COLUMNS; j++)
		{
			if(matrix[i][j] < minElem)
			{
				minElem = matrix[i][j];
			}
		}
		if(minElem != matrix[i][0])
		{
			for(j = i; j < MATRIX_ROWS - deletedRows - 1; j++)
			{
				memmove( matrix[j], matrix[j+1], sizeof(double) * MATRIX_COLUMNS);
			}
			++deletedRows;
			free( matrix[MATRIX_ROWS - deletedRows] );
			--i;
		}
	}
	return deletedRows;
}