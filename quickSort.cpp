// quickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "quickSort.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const int ARRAY = 10;

int _tmain(int argc, _TCHAR* argv[])
{
	int values[ARRAY];
	srand(time(NULL));

	for (int i = 0; i < ARRAY; i++)
	{
		values[i] = rand() % 101;
	}

	printArray(values, 8);
	QuickSort(values, 0, 7);
	cout << "The array has been sorted." << endl;
	printArray(values, 8);
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

int partition(int* array, int pivot, int start, int end)
{
	int left = start; //our left boundry (start of partition we're sorting)
	int right = end; //our right boundry (end of partition we're soring)

	while (left < right) // move our pivot until the boundries meet
	{
		while (pivot < array[right] && right > left) //keep moving until a lesser element is found or until the boundries are equal
		{
			right--; //move left (towards the beginning of our array)
		}
		swap(array[left], array[right]); //after finding a lesser element we swap it with our pivot

		//keep moving until a value greater than or equal to our pivot is 
		//found or our left boundry equals our right
		while (pivot >= array[left] && left < right)
		{
			left++; //move right (towards the end of our array)
		}
		swap(array[right], array[left]); //when a value that is greater than or equal to our pivot we swap them and stop iterating
	}
	return left; //return the split point (where our pivot is)
}

