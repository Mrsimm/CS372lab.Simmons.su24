//Troy Simmons
//CS372
#include <iostream>
#include "pch.h"
using namespace std;
TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}
template <typename T>
class Vector {
public:
	int size()
	{
		return length;
	}
	int capacity()
	{
		return vCapacity;
	}
	T& at(int index)
	{
		if (index < 0 || index > length) {
			cerr << "Vector: index out of bounds on access" << endl;
			exit(1);
		}
		else {
			return vec[index];
		}
	}
	void Vector::put(T data, int pos)
	{
		if (pos == vCapacity) {
			push_back(data);
		}
		else {
			vec[pos] = data;
		}
	}
	void push_back(T data)
	{
		if (length == vCapacity) {
			vCapacity = vCapacity * 2;
		}
		vec[length] = data;
		length++;
	}
private:
	T* vec = new T[1];
	int vCapacity = 1;
	int length = 0;
};
TEST(VectorTest, InitiallyEmpty)
{
	Vector<int> vec;
	EXPECT_EQ(vec.size(), 0);
}
TEST(VectorTest, AddElement)
{
	Vector<int> vec;
	vec.put(2, 1);
	EXPECT_EQ(vec.size(), 1);
}
TEST(VectorTest, RemoveElement)
{
	vector<int> vec;
	vec.push_back(42);
	vec.pop_back();
	EXPECT_TRUE(vec.empty());
	EXPECT_EQ(vec.size(), 0);
}