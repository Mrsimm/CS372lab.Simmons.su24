//Troy Simmons
//CS372
#include <iostream>
#include "pch.h"
using namespace std;
template <typename T, size_t Size>
class Array
{
public:
	void put(T data, size_t index)
	{
		if (index >= Size)
		{
			cout << "Out of range!" << endl;
			return;
		}
		this->data[index] = data;
	}
	T at(size_t index) const
	{
		if (index >= Size)
		{
			cout << "Out of range!" << endl;
			return T();
		}
		return data[index];
	};
	size_t size()
	{
		return Size;
	}
private:
	T data[Size];
};
int main()
{
	Array<int, 3> arr;

	for (size_t i = 0; i <= arr.size() - 1; i++)
	{
		arr.put(i + 3, i);
	}
	for (size_t i = 0; i <= arr.size() - 1; i++)
	{
		cout << arr.at(i) << ", ";
	}
}