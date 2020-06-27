#include "stack.h"
#include "string"
#include "string.h"
#include <fstream>
#include "conio.h"
#include <iostream>
using namespace std;

void main()
{
	//=========Module to get Mathematical Expressions from user and then saving them to file====================================
	int choice; //asks user if he wants to enter another expresssion and saves choice to 'choice'
	string line_write; //string to get infix expression and then writing it to file
	ofstream infix_write ("infix_expression.txt"); //infix expression write file object
	do //loop to ask user if he wants to enter another expression
	{	
		cout<<endl;
		cout<<"Enter Mathematical Expression: "<<endl;
		cin>>line_write;
		infix_write<<line_write; //writing string's whole expression to file
		cout<<endl;
		cout<<"Do you want to enter another expression?"<<endl;
		cout<<"1. YES."<<endl;
		cout<<"2. NO."<<endl;
		cin>>choice;
		if(choice == 1) //moves cursor to next line for new data enterance on choice 1(YES)
		{
			infix_write<<endl; //moves cursor to next line
		}
	}
	while(choice==1); //loop to ask user if he wants to enter another expression
	infix_write.close(); //closing infix write file


	//=========Module to read Infix Exp. from Infix File and converting it to Postfix Exp. and then saving it to Postfix File====
	string line_read; //string to read infix expression from file
	ofstream postfix_write ("postfix_expression.txt");
	ifstream infix_read ("infix_expression.txt"); //infix read file object
	do
	{
	string postfix; //postfix string, declared inside so that on each iteration of new postfix it will be empty
	infix_read>>line_read; //reading string from infix file
	stack op( line_read.length() ); //stack to save operators of infix expression
	for(int i=0; i<line_read.length(); i++)
	{
		if(isdigit(line_read[i]))
		{
			postfix += line_read[i]; //appends the operand to postfix string
		}
		else
		{
			int precedence_stack ; //precedence of operator on top of stack
			int precedence_infix; //precedence of operator in infix expression
			if(!op.isEmpty())
			{
				switch(op._top()) //switch to track operator precedence of operator at top of stack
				{
				case '+':
					{
						precedence_stack = 1;
						break;
					}
				case '-':
					{
						precedence_stack = 1;
						break;
					}
				case '*':
					{
						precedence_stack = 2;
						break;
					}
				case '/':
					{
						precedence_stack =2;
						break;
					}
				}
				switch(line_read[i]) //switch to track operator precedence of operator in infix expression
				{
				case '+':
					{
						precedence_infix = 1;
						break;
					}
				case '-':
					{
						precedence_infix = 1;
						break;
					}
				case '*':
					{
						precedence_infix = 2;
						break;
					}
				case '/':
					{
						precedence_infix =2;
						break;
					}
				}
				if( precedence_infix > precedence_stack) //case if infix operator has high precedence than stack operator
				{
					op.push(line_read[i]);
				}
				else //case if infix operator has low/equal precedence than stack operator
				{
					do //loop to pop operators in stack having precedence greater-than/equal-to infix expression operator 
					{
						postfix += op.pop(); //appends the char to postfix string if its precedence is greater-than/equal-to infix expression operator
						if(!op.isEmpty()) //condition to check if stack is empty
						{
							switch(op._top())
							{
							case '+':
								{
									precedence_stack = 1;
									break;
								}
							case '-':
								{
									precedence_stack = 1;
									break;
								}
							case '*':
								{
									precedence_stack = 2;
									break;
								}
							case '/':
								{
									precedence_stack =2;
									break;
								}
							}
						}
					}
					while( !op.isEmpty() && precedence_stack >= precedence_infix); //checks stack empty or not and precedence of stack operator >= precedence of infix operator
					op.push(line_read[i]); //when no more operator of higher precedence in stack than operator in infix expression OR stack becomes empty it pushes the infix operator to stack
				}
			}
			else //if stack is empty
			{
				op.push(line_read[i]); //push infix operaotor to stack
			}
		}
	}
	while(!op.isEmpty()) //at the end pop all the operators in stack and append them to postfix string
	{
		postfix += op.pop();
	}
	postfix_write<<postfix; //saves postfix expression to postfix file
	postfix_write<<endl; //moves pointer to next line in postfix file
	}
	while(!infix_read.eof());
	infix_read.close();
	postfix_write.close();
	
	
	//=========Module to read and display Infix Expressions and Postfix Expressions==============================================
	ifstream infix_display ("infix_expression.txt");
	ifstream postfix_display ("postfix_expression.txt");
	cout<<endl;
	cout<<"Postfix Expressions <--> Infix Expression"<<endl;
	cout<<"========================================="<<endl;
	do
	{
		string infix; //string to store infix expression
		string postfix; //string to store postfix expression
		infix_display>>infix; //reading infix expression from infix file
		postfix_display>>postfix; //reading postfix expression from postfix file
		cout<<"  "<<infix<<"  =  "<<postfix<<endl; //displaying values
	}
	while( !infix_display.eof()  &&  !postfix_display.eof() ); //read expressions untill end of Infix and Postfix Files
	infix_display.close(); //closing infix file
	postfix_display.close(); //closing postfix file

	getch();
}