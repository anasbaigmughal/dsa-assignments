#include "conio.h"
#include "ctime"
#include <iostream>
using namespace std;

void descendingSelectionSort(int arr[], int size) //to sort elements in descending order
{
	for( int i=0; i<size-1; i++ )
	{
		int maxPos = i;
		int max = arr[i];

		for( int j=i+1; j<size; j++ )
		{
			if( arr[j]>max )
			{
				maxPos = j;
				max = arr[maxPos];
			}
		}
		arr[maxPos] = arr[i];
		arr[i] = max;
	}
}

void selectionSort(int arr[], int size)
{
	for( int i=0; i<size-1; i++ )
	{
		int smallPos = i;
		int smallest = arr[i];

		for( int j=i+1; j<size; j++ )
		{
			if( arr[j]<smallest )
			{
				smallPos = j;
				smallest = arr[smallPos];
			}
		}
		arr[smallPos] = arr[i];
		arr[i] = smallest;
	}
}

void bubbleSort(int arr[], int size)
{
	bool flag = true;
	for( int i=0; i<(size-1) && flag==true; i++ )
	{
		flag =false;
		for( int j=0; j<(size-i-1); j++ ) //on each pass compares from array start
		{
			if( arr[j] > arr[j+1] )
			{
				int temp = arr[j];
				arr[j] = arr[j+1];	
				arr[j+1] = temp;
				flag = true;
			}
		}
	}
}

void insertionSort(int arr[], int size)
{
	for( int i=1;     i<(size);    i++ )
	{
		int temp   =   arr[i];
		int j   =   i-1;
 
		while( temp < arr[j] &&  (j>=0)   )
		{
			arr[ j+1]  =  arr[ j ];   //moves element forward
			j  =  j-1;
		}
 
		arr[j+1]   =   temp;  
	}  
}
 
void merge(int *a, int *b, int low, int pivot, int high)
{
	int h, i, j, k;
	h = low;
	i = low;
	j = (pivot+1);

	while( ( h<=pivot ) && ( j<=high ) )
	{
		if(a[h]<=a[j])
		{
			b[i] = a[h];
			h++;
		}
		else
		{
			b[i]=a[j];
			j++;
		}
		i++;
	}

	if(h>pivot)	
	{
		for(k=j; k<=high; k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	else
	{
		for(k=h; k<=pivot; k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	
	for(k=low; k<=high; k++)
	{
			a[k]=b[k];
	}
}

void mergeSort(int *a, int*b, int low, int high) 
{
	int pivot; 
	if( low<high ) 
	{ 
		pivot=( ( low+high )/2 ); 
		mergeSort( a, b, low, pivot);
		mergeSort(a, b, (pivot+1), high); 
		merge(a, b, low, pivot, high); 
	} 
}

void split( int x[], int first, int last, int &pos )
{
	int pivot = x[first];
	int left = first;
	int right = last;
	while (left < right)
	{
		while( x[right] > pivot)
		{
			right--;
		}
		while( x[left] <= pivot && left < right )
		{ 
			left++;
		}
		if (left < right)
		{
			int temp;
			temp = x[left];
			x[left] = x[right];
			x[right] = temp;
		}
	}
		x[first] = x[right];
		x[right] = pivot;
		pos = right;
}

void quickSort (int x[], int first, int last)
{
	int pos;
	if ( first < last-1)
	{
		split (x, first, last, pos);
		quickSort (x, first, (pos-1));
		quickSort (x, pos + 1, last);
	}
}

//int main()
//{
//	int n;
//	cout<<"Enter Array Size:"<<endl;
//	cin>>n;
//	//NOTE: Below individual arrays are declred for each sorting algorithm and then initialized with same elements to keep consistency in comparing algorithms working with same elements of array
//	int *a = new int [n]; //array for bubble sorting
//	int *b = new int [n]; //array for selection sorting
//	int *c = new int [n]; //array for insertion sorting
//	int *d = new int [n]; //array for merge sorting
//	int *e = new int [n]; //array for quick sorting
//	int *x = new int [n]; //array for merge sorting
//	for(int i=0; i<n; i++) //initializing each array with same random numbers
//	{
//		a[i] = b[i] = c[i] = d[i] = e[i] = (rand() % n);
//	}
//
//	//=======================================================================================
//	//bubble sorting
//	//=======================================================================================
//	cout<<endl;
//	cout<<"Bubble Sort Result:"<<endl;
//	cout<<"==================="<<endl;
//	bubbleSort(a, n);
//	for( int i=0; i<n; i++ )
//	{
//		cout<<a[i]<<"  ";
//	}
//
//	//=======================================================================================
//	//selection sorting
//	//=======================================================================================
//	cout<<endl;
//	cout<<endl;
//	cout<<"Selection Sort Result:"<<endl;
//	cout<<"======================"<<endl;
//	selectionSort(b, n);
//	for( int i=0; i<n; i++ )
//	{
//		cout<<b[i]<<"  ";
//	}
//	
//
//	//=======================================================================================
//	//insertion sorting
//	//=======================================================================================
//	cout<<endl;
//	cout<<endl;
//	cout<<"Insertion Sort Result:"<<endl;
//	cout<<"======================"<<endl;
//	insertionSort(c, n);
//	for( int i=0; i<n; i++ )
//	{
//		cout<<c[i]<<"  ";
//	}
//
//	//=======================================================================================
//	//merge sorting
//	//=======================================================================================
//	cout<<endl;
//	cout<<endl;
//	cout<<"Merge Sort Result:"<<endl;
//	cout<<"=================="<<endl;
//	mergeSort(d, x, 0, n-1);
//	for( int i=0; i<n; i++ )
//	{
//		cout<<d[i]<<"  ";
//	}
//	
//	//=======================================================================================
//	//quick sorting
//	//=======================================================================================
//	cout<<endl;
//	cout<<endl;
//	cout<<"Quick Sort Result:"<<endl;
//	cout<<"=================="<<endl;
//	quickSort(e, 0, n-1);
//	for( int i=0; i<n; i++ )
//	{
//		cout<<e[i]<<"  ";
//	}
//
//	//=======================================================================================
//	//descending selection sorting
//	//=======================================================================================
//	cout<<endl;
//	cout<<endl;
//	cout<<"Descending Order Sort Result:"<<endl;
//	cout<<"============================="<<endl;
//	descendingSelectionSort(e, n);
//	for( int i=0; i<n; i++ )
//	{
//		cout<<e[i]<<"  ";
//	}
//
//	getch();
//}

//int main()
//{
//	int n;
//	cout<<"Enter Array Size:"<<endl;
//	cin>>n;
//	//NOTE: Below individual arrays are declred for each sorting algorithm and then initialized with same elements to keep consistency in comparing algorithms working with same elements of array
//	int *a = new int [n]; //array for bubble sorting
//	int *b = new int [n]; //array for selection sorting
//	int *c = new int [n]; //array for insertion sorting
//	int *d = new int [n]; //array for merge sorting
//	int *e = new int [n]; //array for quick sorting
//	int *x = new int [n]; //array for merge sorting
//	for(int i=0; i<n; i++) //initializing each array with same random numbers
//	{
//		a[i] = b[i] = c[i] = d[i] = e[i] = (rand() % n);
//	}
//
//	//=======================================================================================
//	//bubble sorting
//	//=======================================================================================
//	cout<<endl;
//	cout<<"Bubble Sort Result:"<<endl;
//	cout<<"==================="<<endl;
//	clock_t a_time;
//	a_time = clock();
//	bubbleSort(a, n);
//	a_time = clock() - a_time;
//	cout<<"Running Time: "<<(float)a_time/CLOCKS_PER_SEC<<" Seconds."<<endl;
//	
//
//	//=======================================================================================
//	//selection sorting
//	//=======================================================================================
//	cout<<endl;
//	cout<<endl;
//	cout<<"Selection Sort Result:"<<endl;
//	cout<<"======================"<<endl;
//	a_time = clock();
//	selectionSort(c, n);
//	a_time = clock() - a_time;
//	cout<<"Running Time: "<<(float)a_time/CLOCKS_PER_SEC<<" Seconds."<<endl;
//
//	//=======================================================================================
//	//insertion sorting
//	//=======================================================================================
//	cout<<endl;
//	cout<<endl;
//	cout<<"Insertion Sort Result:"<<endl;
//	cout<<"======================"<<endl;
//	a_time = clock();
//	insertionSort(b, n);
//	a_time = clock() - a_time;
//	cout<<"Running Time: "<<(float)a_time/CLOCKS_PER_SEC<<" Seconds."<<endl;
//
//	//=======================================================================================
//	//merge sorting
//	//=======================================================================================
//	cout<<endl;
//	cout<<endl;
//	cout<<"Merge Sort Result:"<<endl;
//	cout<<"=================="<<endl;
//	a_time = clock();
//	mergeSort(d, x, 0, n-1);
//	a_time = clock() - a_time;
//	cout<<"Running Time: "<<(float)a_time/CLOCKS_PER_SEC<<" Seconds."<<endl;
//
//	//=======================================================================================
//	//quick sorting
//	//=======================================================================================
//	cout<<endl;
//	cout<<endl;
//	cout<<"Quick Sort Result:"<<endl;
//	cout<<"=================="<<endl;
//	a_time = clock();
//	quickSort(e, 0, n-1);
//	a_time = clock() - a_time;
//	cout<<"Running Time: "<<(float)a_time/CLOCKS_PER_SEC<<" Seconds."<<endl;
//	
//	getch();
//}

//int main()
//{
//	int n;
//	cout<<"Enter Array Size:"<<endl;
//	cin>>n;
//	int *a = new int [n]; //dynamic array
//	int *x = new int [n]; //dynamic array
//	for(int i=0; i<n; i++) //initializing array with random numbers
//	{
//		a[i] = (rand() % n);
//	}
//
//	//=======================================================================================
//	//bubble sorting
//	//=======================================================================================
//	cout<<endl;
//	cout<<"Bubble Sort Result:"<<endl;
//	cout<<"==================="<<endl;
//	quickSort(a, 0, n-1); //make array already sorted for best case check
//	clock_t a_time = clock(); //initializing clock
//	bubbleSort(a, n); //checking for best case as array is already sorted
//	a_time = clock() - a_time; //calculating clock difference
//	cout<<"Best Case Scenerio Running Time: "<<(float)a_time/CLOCKS_PER_SEC<<" Seconds."<<endl;
//	descendingSelectionSort(a, n); //make array reversed for worst case check
//	a_time = clock(); //initializing clock
//	bubbleSort(a, n); //checking for worst case as array is reversely ordered
//	a_time = clock() - a_time; //calculating clock difference
//	cout<<"Worst Case Scenerio Running Time: "<<(float)a_time/CLOCKS_PER_SEC<<" Seconds."<<endl;
//
//	//=======================================================================================
//	//selection sorting
//	//=======================================================================================
//	cout<<endl<<endl;
//	cout<<"Selection Sort Result:"<<endl;
//	cout<<"======================"<<endl;
//	//array already sorted for best case check
//	a_time = clock(); //initializing clock
//	selectionSort(a, n); //checking for best case as array is already sorted
//	a_time = clock() - a_time; //calculating clock difference
//	cout<<"Best Case Scenerio Running Time: "<<(float)a_time/CLOCKS_PER_SEC<<" Seconds."<<endl;
//	descendingSelectionSort(a, n); //make array reversed for worst case check
//	a_time = clock(); //initializing clock
//	selectionSort(a, n); //checking for worst case as array is reversely ordered
//	a_time = clock() - a_time; //calculating clock difference
//	cout<<"Worst Case Scenerio Running Time: "<<(float)a_time/CLOCKS_PER_SEC<<" Seconds."<<endl;
//
//	//=======================================================================================
//	//insertion sorting
//	//=======================================================================================
//	cout<<endl<<endl;
//	cout<<"Insertion Sort Result:"<<endl;
//	cout<<"======================"<<endl;
//	//array already sorted for best case check
//	a_time = clock(); //initializing clock
//	insertionSort(a, n); //checking for best case as array is already sorted
//	a_time = clock() - a_time; //calculating clock difference
//	cout<<"Best Case Scenerio Running Time: "<<(float)a_time/CLOCKS_PER_SEC<<" Seconds."<<endl;
//	descendingSelectionSort(a, n); //make array reversed for worst case check
//	a_time = clock(); //initializing clock
//	insertionSort(a, n); //checking for worst case as array is reversely ordered
//	a_time = clock() - a_time; //calculating clock difference
//	cout<<"Worst Case Scenerio Running Time: "<<(float)a_time/CLOCKS_PER_SEC<<" Seconds."<<endl;
//	
//	//=======================================================================================
//	//merge sorting
//	//=======================================================================================
//	cout<<endl<<endl;
//	cout<<"Merge Sort Result:"<<endl;
//	cout<<"=================="<<endl;
//	//array already sorted for best case check
//	a_time = clock(); //initializing clock
//	mergeSort(a, x, 0, n-1); //checking for best case as array is already sorted
//	a_time = clock() - a_time; //calculating clock difference
//	cout<<"Best Case Scenerio Running Time: "<<(float)a_time/CLOCKS_PER_SEC<<" Seconds."<<endl;
//	descendingSelectionSort(a, n); //make array reversed for worst case check
//	a_time = clock(); //initializing clock
//	mergeSort(a, x, 0, n-1); //checking for worst case as array is reversely ordered
//	a_time = clock() - a_time; //calculating clock difference
//	cout<<"Worst Case Scenerio Running Time: "<<(float)a_time/CLOCKS_PER_SEC<<" Seconds."<<endl;
//
//	//=======================================================================================
//	//quick sorting
//	//=======================================================================================
//	cout<<endl<<endl;
//	cout<<"Quick Sort Result:"<<endl;
//	cout<<"=================="<<endl;
//	//array already sorted for best case check
//	a_time = clock(); //initializing clock
//	quickSort(a, 0, n-1); //checking for best case as array is already sorted
//	a_time = clock() - a_time; //calculating clock difference
//	cout<<"Best Case Scenerio Running Time: "<<(float)a_time/CLOCKS_PER_SEC<<" Seconds."<<endl;
//	descendingSelectionSort(a, n); //make array reversed for worst case check
//	a_time = clock(); //initializing clock
//	quickSort(a, 0, n-1); //checking for worst case as array is reversely ordered
//	a_time = clock() - a_time; //calculating clock difference
//	cout<<"Worst Case Scenerio Running Time: "<<(float)a_time/CLOCKS_PER_SEC<<" Seconds."<<endl;
//
//	getch();
//}