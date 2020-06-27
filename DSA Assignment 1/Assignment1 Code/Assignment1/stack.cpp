#include "stack.h"
#include <iostream>
using namespace std;

stack::stack(void)
{
	size = 100;
	arrStack = new char [size];
	top = -1;
}

stack::stack(int size)
{
	this->size = size;
	arrStack = new char [this->size];
	top = -1;
}

bool stack::isEmpty()
{
	if(top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool stack::isFull()
{
	if(top == (size-1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void stack::push(char value)
{
	if(!isFull())
	{
		arrStack[++top] = value;
	}
	else
	{
		cout<<"Stack Overflow!!!"<<endl;
	}
}

char stack::pop()
{
	if(!isEmpty())
	{
		return (arrStack[top--]);
	}
	else
	{
		cout<<"Stack Underflow!!!"<<endl;
	}
}

char stack::_top()
{
	if(!isEmpty())
	{
		return arrStack[top];
	}
	else
	{
		cout<<"Stack Empty!!!";
	}
}

void stack::display()
{
	for(int i=top; i>=0; i--)
	{
		cout<<arrStack[i];
	}
}
