//
// File:   assignment1.cpp
// Author: Troy Simmons
// Purpose: 
// Illustrate some of the bad thins that can happen with
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
	while (searcher <= size)
	{
		ptr[searcher] = searcher + 2;
		cout << ptr[searcher] << ", ";
		searcher = searcher + 1;
	}
	int* ptr2 = ptr;

	delete[] ptr;
	int searcher2 = 0;
	cout << "These are the results of the second pointer after the first one is deleted" << endl;
	while (searcher2 <= size)
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