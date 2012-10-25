/** 
 * @file	MainTask2.cpp 
 * @brief	Defines the entry point for the console application.
 *
 * @author	Pavlo Vons
 * @date	21 October 2012
 * 
 */

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "MatrixOperations.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int i, j, deletedRows, c='1', matrixIsEntered = 0, isNumber = 0;
	double **matrix;
	char *buff;

	try
    {
		buff = (char *) malloc(MATRIX_ROWS * sizeof(char));
		matrix = (double **) malloc(MATRIX_ROWS * sizeof(double *));
		for(i = 0; i < MATRIX_ROWS; i++)
			matrix[i] = (double *) malloc(MATRIX_COLUMNS * sizeof(double));
    }
    catch(bad_alloc& err)
    {
        cout << err.what() << '\n';
		return 0;
    }
	
	cout <<"This program removes from a given matrix of real numbers\n"
		 <<"	all rows in which the minimum element is not the first.\n\n";
	cout <<"Main menu. Please choose what operation do you want to be completed:\n"
		 <<"1-Enter matrix.\n"
		 <<"2-Modify matrix.\n"
		 <<"3-Show matrix.\n"
		 <<"4-Show main menu.\n"
		 <<"5-About.\n"
		 <<"0-Exit.\n"
		 <<" -> ";

	while(c != '0')
	{
		c = _getch();
		cout << (char)c << endl;
		switch(c)
		{
			case '1':
				for(i = 0; i < MATRIX_ROWS; i++)
				{
					for(j = 0; j < MATRIX_COLUMNS; j++)
					{
						cout << "Input a[" << i << "][" << j << "]=";
						cin >> buff;
						if( strcmp(buff,"0") == 0)
						{
							matrix[i][j] = 0;
						}
						else
						{
							matrix[i][j] = atof(buff);
							if(matrix[i][j] == 0)
							{
								cout << "Input error. Try again\n";
								--j;
							}
						}
					}
				}
				deletedRows = 0;
				matrixIsEntered = 1;
				cout << "Operation Completed.\n -> ";
				continue;
			case '2':
				if(matrixIsEntered == 0)
				{
					cout << "Matrix is not entered.\n -> ";
				}
				else
				{
					deletedRows = ModifyMatrix (matrix);
					cout << "Operation Completed. Number of deleted rows is "
						<< deletedRows << endl << " -> ";
				}
				continue;
			case '3':
				if(matrixIsEntered == 0)
				{
					cout << "Matrix is not entered.\n -> ";
				}
				else
				{
					for(i = 0; i < MATRIX_ROWS - deletedRows; i++)
					{
						for(j = 0; j < MATRIX_COLUMNS; j++)
						{
							cout << matrix[i][j]<<" ";
						}
						cout << endl;
					}
					cout << " -> ";
				}
				continue;
			case '4':
				cout <<"Menu:\n"
					<<"1-Enter matrix.\n"
					<<"2-Modify matrix.\n"
					<<"3-Show matrix.\n"
					<<"4-Show main menu.\n"
					<<"5-About.\n"
					<<"0-Exit.\n"
					<<" -> ";
				continue;
			case '5':
				cout <<"GlobalLogic Base Camp. Task 3. Number 12.\n -> ";
				continue;
			case '0':
				free(matrix);
				cout <<"Thank you for choosing our application.\n";
				getchar();
				return 0;
			default:
				cout<<"Input error. Try again\n -> ";
				continue;
		}
	}	
	return 0;
}

