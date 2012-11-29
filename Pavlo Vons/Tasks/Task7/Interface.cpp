/** 
 * @file	Interface.cpp
 * @brief	Contain methods and class for working with queue
 *
 * @author	Pavlo Vons
 * @date	28 November 2012
 * 
 */

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include "Interface.h"

using namespace std;

template< typename T >
struct QueueElem
{
	T i;
	QueueElem *next;
	QueueElem(): i(), next(nullptr)
	{

	}
	QueueElem(T ti, QueueElem *tnext)
	{
		i = ti;
		next = tnext;
	}
};

template< typename T >
class Queue
{
	QueueElem<T> *queueStart, *queueEnd;
public:
	Queue()
	{
		queueStart = nullptr;
		queueEnd = nullptr;
	}
	Queue(Queue &q)
	{
		if(q.queueStart != nullptr)
		{
			QueueElem *tempS, *tempD;
			tempS = q.queueStart;
			try
			{
				queueStart = new QueueElem(tempS->i, nullptr);
			}
			catch(std::bad_alloc)
			{
				std::cout << "Bad allocation error!";
			}			
			tempD = queueStart;
			while(tempS->next != nullptr)
			{
				tempS=tempS->next;
				try
				{
					tempD->next = new QueueElem(tempS->i, nullptr);
				}
				catch(std::bad_alloc)
				{
					std::cout << "Bad allocation error!";
				}	
				tempD = tempD->next;
			}
			queueEnd = tempD;
		}
	}
	~Queue()
	{
		if(queueStart != nullptr)
		{
			QueueElem *tempF, *tempN;
			tempF = queueStart;
			do
			{
				tempN = tempF->next;
				delete tempF;
				tempF = tempN;
			}
			while(tempF != nullptr);
		}
	}
	UI PushElem(T elem)
	{
		if( IsEmpty() )
		{
			try
			{
				queueStart = new QueueElem<T>(elem, nullptr);
			}
			catch(std::bad_alloc)
			{
				return 0;
			}
			queueEnd = queueStart;
		}
		else
		{
			try
			{
				queueEnd->next = new QueueElem<T>(elem, nullptr);
			}
			catch(std::bad_alloc)
			{
				return 0;
			}
			queueEnd = queueEnd->next;
		}
		return 1;
	}
	UI PopElem()
	{
		if( !IsEmpty() )
		{
			if(queueStart == queueEnd)
			{
				delete queueStart;
				queueEnd = nullptr;
				queueStart = nullptr;
			}
			else
			{
				QueueElem<T> *temp = queueStart;
				queueStart = queueStart->next;
				delete temp;
			}
		}
		else
		{
			cout << "Queue is empty!\n";
		}
		return 1;
	}
	bool IsEmpty()
	{
		if(queueStart == nullptr)
			return 1;
		else 
			return 0;
	}
	void PrintQueue()
	{
		if(queueStart == nullptr)
			cout << "Queue is empty!\n";
		else
		{
			QueueElem<T> *temp = queueStart;
			while(temp != nullptr)
			{
				cout << "[" << temp->i << "] ";
				temp = temp->next;
			}
			cout << "\n";
		}
	}
};

void Start(void)
{
	Queue<int> *qi = new Queue<int>();
	Queue<double> *qd = new Queue<double>();
	Queue<string> *qs = new Queue<string>();
	bool queueCreated = false;	
	char c = '1', c2, qw = 'i';
	while(c != '0')
	{		
		cout << "Main menu:\n1 - Create queue.\n2 - Add element to queue.\n3 - Remove element from queue.\n4 - Show queue.\n0 - Exit.\n";
		c = _getch();
		switch(c)
		{
		case '1':
			if(!queueCreated)
			{
				queueCreated = true;
				cout << "Choose type for queue:\n1 - Integer.\n2 - Double.\n3 - String.\n";
				c2 = _getch();
				switch(c2)
				{
				case '1':
					qw = 'i';
					cout << "Operation successfully!\n";
					break;
				case '2':
					qw = 'd';
					cout << "Operation successfully!\n";
					break;
				case '3':
					qw = 's';
					cout << "Operation successfully!\n";
					break;
				default:
					queueCreated = false;
					cout << "Incorrect input data!\n";
					break;
				}
			}
			else
			{
				cout << "Queue is already created!\n";
			}
			break;
		case '2':
			if(queueCreated)
			{
				cout << "Input element:\n";
				char *ct = new char[1000];
				cin.getline(ct, 1000);
				switch(qw)
				{
				case 'i':
					{
						int it = atoi(ct);
						qi->PushElem(it);
					}
					break;
				case 'd':
					{	
						double dt = atof(ct);
						qd->PushElem(dt);
					}
					break;
				case 's':
					{
						qs->PushElem(ct);
					}
					break;
				default:

					break;
				}
			}
			else 
			{
				cout << "Queue is not created!\n";
			}
			break;
		case '3':
			if(queueCreated)
			{
				switch(qw)
				{
				case 'i':
					qi->PopElem();
					break;
				case 'd':
					qd->PopElem();
					break;
				case 's':
					qs->PopElem();
					break;
				default:
					break;
				}
			}
			else 
			{
				cout << "Queue is not created!\n";
			}
			break;
		case '4':
			if(queueCreated)
			{
				switch(qw)
				{
				case 'i':
					qi->PrintQueue();
					break;
				case 'd':
					qd->PrintQueue();
					break;
				case 's':
					qs->PrintQueue();
					break;
				default:

					break;
				}
			}
			else 
			{
				cout << "Queue is not created!\n";
			}
			break;
		case '0':
			cout << "Thank you for choosing our application!\n";
			c2 = _getch();
			break;
		default:
			cout << "Incorrect input data!\n";
			break;
		}		
	}
}

