#include "node.h"

#pragma once
class list
{
public:
	node *head;
public:
	list(void);
	bool isEmpty();
	void addNode(int, int);
	list operator + (list);
	list operator * (list);
	int power(int, int);
	int solve(int);
	void display();
};

