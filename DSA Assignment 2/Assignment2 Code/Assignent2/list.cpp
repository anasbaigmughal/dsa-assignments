#include "list.h"
#include <math.h>  
#include <stdio.h>  
#include "node.h"
#include <iostream>
using namespace std;

list::list(void)
{
	head = '\0';
}

bool list::isEmpty()
{
	if( head == '\0' ) //condition for empty list
	{
		return true;
	}
	else
	{
		return false;
	}
}

void list::addNode(int coefficient, int degree) //logic of addNode() is based on 'insert at end'
{
	node *ptr = new node; //node creation
	ptr->coefficient = 0;
	ptr->degree = 0;
	ptr->next = '\0';

	ptr->coefficient = coefficient; //assigning values
	ptr->degree = degree; //assigning values

	if( isEmpty() ) //empty list
	{
		head = ptr;
	}
	else
	{
		node *temp = head;

		while ( temp->next != '\0' ) //traverse to the last node
		{
			temp = temp->next;
		}

		temp->next = ptr;
	}
}

list list::operator + (list l) //operator '+' overloaded for addition
{
	list r; //to store addition result in that list 

	node *t1 = head; //point to 1st list's head
	node *t2 = l.head; //point to 2nd list's head

	while( t1 != '\0' || t2 != '\0' ) //keep loop running until any list's head != '\0'
	{
		if( t1 != '\0' && t2 != '\0') //if pointer to both of the lists is not reached at end
		{
			if( t1->degree == t2->degree ) //multiplies only those terms with same degree
			{
				r.addNode( ( t1->coefficient + t2->coefficient), t1->degree);
				t1 = t1->next; //moves first list to next
				t2 = t2->next; //moves second list to next
			}
			else if( t1->degree > t2->degree) //if degree of first node > second node
			{
				r.addNode(t1->coefficient, t1->degree);
				t1 = t1->next; //moves first list to next
			}
			else if( t1->degree < t2->degree) //if degree of first node < second node
			{
				r.addNode(t2->coefficient, t2->degree);
				t2 = t2->next; //moves second list to next
			}
		}
		else if( t1 == '\0') //if first list is reached at end
		{
			r.addNode(t2->coefficient, t2->degree);
			t2 = t2->next; //moves second list to next because as is still remaining
		}
		else if( t2 == '\0') //if second list is reached at end
		{
			r.addNode(t1->coefficient, t1->degree);
			t1 = t1->next; //moves first list to next because as is still remaining
		}
	}
	return r; //returning resultant list to main
}

list list::operator * (list l)
{
	//=================Below Module will multiply first not full solve============= 
	list r; //to store mutiplication result in that list 

	node *t1 = head; //point to 1st list's head
	node *t2 = l.head; //point to 2nd list's head

	while ( t1 != '\0' )
	{
		while( t2 != '\0' )
		{
			r.addNode( ( t1->coefficient * t2->coefficient ), ( t1->degree + t2->degree ) );
			t2 = t2->next;
		}
		t1 = t1->next;
		t2 = l.head;
	}
	//=================Module below will now solve the multiplied solution further====================
	node *t = r.head; //point to list's head
	int max = t->degree; 
	list res;

	while (t != '\0') //calculates maximum degree in the list 
	{
		if( t->degree > max )
		{
			max = t->degree;
		}
		t = t->next;
	}

	t = r.head;

	for( int i=max; i>=0; i--) //it will solve the terms which have same degree in the whole equation
	{
		int coefficient = 0;
		int degree = 0;

		while(t != '\0' )
		{
			if(t->degree == i)
			{
				coefficient = coefficient + t->coefficient; //it adds coefficients of those terms which have same degree
				degree = t->degree;
			}
			t = t->next;
		}
		t = r.head;
		if(coefficient != 0 )
		{
			res.addNode(coefficient, degree); //it adds nodes sequentially to list 'res'
		}
	}
	return res;
}

int list::power(int base, int exponent) //recursion is used to calulate "base^exponent"
{
	if(exponent != 0)
	{
		if( exponent == 1 ) //base case
		{
			return ( base );
		}
		else //general case
		{
			return ( base * power( base, exponent-1) );
		}
	}
	else //condition if "exponent == 0" i.e. x^0
	{
		return (1);
	}
}

int list::solve(int point) //function to solve equation
{
	node *temp = head;
	int sum = 0;
	double multiplication;

	while( temp != '\0' )
	{
		multiplication = ( (temp->coefficient)*( power( point, temp->degree ) ) );
		sum = sum + multiplication;
		temp = temp->next;
	}
	return sum;
}

void list::display() //function to display list
{
	node *temp = head;

	while ( temp != '\0' ) //traverse until reached at end
	{
		cout<<temp->coefficient<<"x^"<<temp->degree;

		if(temp->next == '\0') //just to eliminate '+' sign at end of the equation
		{
		}
		else
		{
			cout<<"  +  ";
		}
		temp = temp->next;
	}
}