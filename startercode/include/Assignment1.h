//
// File:   assignment1.cpp
// Author: Troy Simmons
// Purpose: Show the anti-practices with pointers
// Illustrate some of the bad things that can happen with
// pointers
//
#include <iostream>
#include <string>
using namespace std;
void BadPointer1();
void BadPointer2();
string* BadPointer3();
void BadPointer4();


void BadPointer1()
{
	int size = 10;
	int searcher = 0;
	int* ptr = new int[size];
	cout << "These are the numbers for the first pointer (Part 1)" << endl;
	while (searcher <= size) //Initialize all variables in the array and output them
	{
		ptr[searcher] = searcher + 2;
		cout << ptr[searcher] << ", ";
		searcher = searcher + 1;
	}
	cout << endl;
	int* ptr2 = ptr;

	delete[] ptr;
	int searcher2 = 0;
	cout << "These are the results of the second pointer after the first one is deleted (Part 1)" << endl;
	while (searcher2 <= size) //search the second pointer, which is set to be equal to the original pointer, after the original pointer has been deleted
	{
		cout << ptr2[searcher2] << ", ";
		searcher2++;
	}
	cout << endl;
}

void BadPointer2()
{
	int size = 10;
	int searcher = 0;
	int* ptr = new int[size];
	int* ptr2 = ptr;
	cout << "These are the numbers for the first pointer (Part 2)" << endl;
	while (searcher <= size) //Initialize all variables in the array and output them
	{
		ptr[searcher] = searcher + 5;
		cout << ptr[searcher] << ",";
		searcher = searcher + 1;
	}
	cout << endl;


	delete[] ptr;
	int searcher2 = 0;
	cout << "These are the results of the first pointer after it is deleted (Part 2)" << endl;
	cout << *ptr2 << endl; //Print the address of the second pointer after the first one has been deleted
	while (searcher2 <= size)
	{
		cout << ptr[searcher2]; //output all elements of the first array after it has been deleted
		searcher2++;
	}
	cout << endl;
}


string* BadPointer3()
{
	string* ptr;
	ptr = new string("Doughnut");
	return ptr;
}
void BadPointer4()
{
	string* str = BadPointer3();
	cout << "This is the string from the third function (Part 3):" << *str;
}




int main()
{
	BadPointer1();
	BadPointer2();
	BadPointer4();
	return 0;
}