#pragma once
class stack
{
private:
	char *arrStack;
	int top;
	int size;
public:
	stack(void);
	stack(int);
	bool isEmpty();
	bool isFull();
	void push(char);
	char pop();
	char _top();
	void display();
};