//
// File:   assignment1.cpp
// Author: Troy Simmons
// Purpose: Show the anti-practices with pointers
// Illustrate some of the bad things that can happen with
// pointers
//
#include <iostream>
using namespace std;
void BadPointer1();
void BadPointer2();

void BadPointer1()
{
	int size = 10;
	int searcher = 0;
	int* ptr = new int[size];
	cout << "These are the numbers for the first pointer on Part 1" << endl;
	while (searcher <= size) //Initialize all variables in the array and output them
	{
		ptr[searcher] = searcher + 2;
		cout << ptr[searcher] << ", ";
		searcher = searcher + 1;
	}
	int* ptr2 = ptr;

	delete[] ptr;
	int searcher2 = 0;
	cout << "These are the results of the second pointer after the first one is deleted" << endl;
	while (searcher2 <= size) //search the second pointer, which is set to be equal to the original pointer, after the original pointer has been deleted
	{
		cout << ptr2[searcher2] << ", ";
		searcher2++;
	}
}

void BadPointer2()
{
	int size = 10;
	int searcher = 0;
	int* ptr = new int[size];
	int* ptr2 = ptr;
	cout << "These are the numbers for the first pointer on Part 2" << endl;
	while (searcher <= size)
	{
		ptr[searcher] = searcher + 5;
		cout << ptr[searcher] << endl;
		searcher = searcher + 1;
	}
	

	delete[] ptr;
	int searcher2 = 0;
	cout << "These are the results of the second pointer after the first one is deleted" << endl;
	cout << *ptr2;
	while (searcher2 <= size)
	{
		cout << ptr[searcher2];
		searcher2++;
	}
}
int main()
{
	BadPointer1();
	BadPointer2();
	return 0;
}
