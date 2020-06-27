#include "list.h"
#include "node.h"
#include "conio.h"
#include <string>
#include <cstdlib>
#include <sstream>
#include "fstream"
#include <iostream>
using namespace std;

void stringToList(string readList, list *l)
{
	readList += '+'; //added at end of string to evaluate till end
	string coefficientString; //to store coefficient string
	string degreeString; //to store degree string
	int lengthCoefficient; //to store coefficient length
	int lengthDegree; //to store degree string
	int coefficientStart = 0; //coefficient start position in string
	int coefficientEnd = 0; //coefficient end position in string
	int degreeStart = 0; //degree start position in string
	int degreeEnd = 0; //degree end position in string
	int coefficientNumber; //to store coefficient value
	int degreeNumber; //to store degree value

	for(int i=0; i<readList.length(); i++)
	{
		if( readList[i] == 'X' || readList[i] == 'x' ) //char == 'x' or 'X' it will take previous value as coefficient
		{
			coefficientEnd = i;
			lengthCoefficient = ( coefficientEnd - coefficientStart );
			coefficientString = readList.substr( coefficientStart, lengthCoefficient );

			stringstream convert(coefficientString);
			convert>>coefficientNumber;
		}

		if( readList[i] == '^' ) //if char == '^' it will set start position for degree at this point 
		{
			degreeStart = ( i+1 );
		}

		if( readList[i] == '+' ) //if char == '+' it will take previous value as degree
		{
			degreeEnd = i;
			lengthDegree = ( degreeEnd - degreeStart );
			degreeString = readList.substr( degreeStart, lengthDegree );

			stringstream convert( degreeString );
			convert>>degreeNumber;

			coefficientStart = (i+1);
			l->addNode(coefficientNumber, degreeNumber);
		}
	}
}

void main()
{
	list list1;
	list list2;
	list additionList;
	list multiplicationList;
	int value;

	//==============GETTING USER INPUT AND, WRITING POLYNOMIAL EQUATION TO FILE==============
	string writeList; //to store polynomial equation to string

	ofstream file_write("polynomial.txt");
	
	cout<<"Enter Polynomial Equation-1:"<<endl;
	getline( cin, writeList );
	cout<<endl;
	file_write<<writeList; //writing plynomial equation-1 to file
	
	file_write<<endl;

	cout<<"Enter Polynomial Equation-2:"<<endl;
	getline( cin, writeList );
	cout<<endl;
	file_write<<writeList; //writing plynomial equation-2 to file

	file_write.close();
	cout<<"Writing equations to File. . ."<<endl;

	//==========================READING POLYNOMIAL EQUATION FROM FILE========================
	ifstream file_read("polynomial.txt");
	string readList1; //to store polynomial equation-1
	string readList2; //to store polynomial equation-2

	file_read>>readList1; //reading polynomial equaton-1 to string from file
	file_read>>readList2; //reading polynomial equaton-2 to string from file
	cout<<endl<<"Reading equations from File. . ."<<endl;
	
	//======================CONVERTING POLYNOMIAL EQUATION STRING TO LIST====================
	stringToList(readList1, &list1);
	stringToList(readList2, &list2);

	//=========================DISPLAYING POLYNOMIAL EQUATION 1 & 2==========================
	cout<<endl<<"POLYNOMIAL EQUATION-1:"<<endl;
	cout<<"======================"<<endl;
	list1.display();
	cout<<endl;
	cout<<endl<<"POLYNOMIAL EQUATION-2:"<<endl;
	cout<<"======================"<<endl;
	list2.display();
	cout<<endl;

	//=================ADDING POLYNOMIAL EQUATION 1 & 2 AND DISPLAYING RESULT================
	additionList = list1 + list2;
	cout<<endl<<"ADDITION RESULT:"<<endl;
	cout<<"================"<<endl;
	additionList.display();
	cout<<endl;

	//=============MULTIPLYING POLYNOMIAL EQUATION 1 & 2 AND DISPLAYING RESULT===============
	multiplicationList = list1 * list2;
	cout<<endl<<"MULTIPLICATION RESULT:"<<endl;
	cout<<"======================"<<endl;
	multiplicationList.display();
	cout<<endl;

	//========================EVALUATING POLYNOMIAL AT GIVEN POINT===========================
	cout<<endl<<"Enter value of X to evaluate Polynomial-1:"<<endl;
	cin>>value;
	cout<<endl<<"POLYNOMIAL EQUATION-1 EVALUATION AT X = "<<value<<":"<<endl;
	cout<<"=========================================="<<endl;
	cout<<list1.solve(value);
	cout<<endl;
	cout<<endl<<"Enter value of X to evaluate Polynomial-2:"<<endl;
	cin>>value;
	cout<<endl<<"POLYNOMIAL EQUATION-2 EVALUATION AT X = "<<value<<":"<<endl;
	cout<<"=========================================="<<endl;
	cout<<list2.solve(value);

	getch();
}