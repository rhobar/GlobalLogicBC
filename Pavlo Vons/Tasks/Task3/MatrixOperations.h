/** 
 * @file	MatrixOpeartions.h
 * @brief	Contain functions prototypes for working with matrix
 *
 * @author	Pavlo Vons
 * @date	26 October 2012 
 */

#ifndef _MATRIXOPERATIONS_H_
#define _MATRIXOPERATIONS_H_

#define STR_SIZE 30
#define MATRIX_ROWS 3
#define MATRIX_COLUMNS 3

/**
  * @brief		This function removes from matrix of real numbers
				all rows in which the minimum element is not the first.
  * @param		[in] array of pointers - begin of array
  * @return		unsigned int - number of removed columns
  */
unsigned int ModifyMatrix (double **matrix);

#endif /* _MATRIXOPERATIONS_H_ */