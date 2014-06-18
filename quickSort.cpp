// quickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void printArray(int* array, int n);
void QuickSort(int* array, int start, int end);
int partition(int* array, int pivotValue, int start, int end);
void swap(int &a, int &b);

int _tmain(int argc, _TCHAR* argv[])
{


	cin.get();
	return 0;
}

void swap(int&a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void printArray(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << endl;
	}
}

void QuickSort(int* array, int start, int end)
{
	int pivot = array[start]; //start with the first element in our array as our pivot
	int splitPoint;

	// if the end and start indexes are equal it means there is only one element
	// and quicksort's job is done
	if (end > start)
	{
		// the partition funtion returns the place of or pivot after figuring out where
		// it belongs in our array. 
		splitPoint = partition(array, pivot, start, end);
		array[splitPoint] = pivot;
		QuickSort(array, start, splitPoint - 1);
		QuickSort(array, splitPoint + 1, end);
	}
}

