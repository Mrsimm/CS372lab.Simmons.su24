#include "pch.h"
#include "ListforFinal.h"
typedef List<int> IntList;

TEST(ListTest, PartitionTest) 
{
    IntList list;
    list.push_back(3);
    list.push_back(1);
    list.push_back(5);
    list.push_back(2);
    list.push_back(4);

    IntList* lessThanList = nullptr;
    IntList* greaterThanOrEqualList = nullptr;

    list.partition(3, lessThanList, greaterThanOrEqualList);

    ASSERT_EQ(lessThanList->getSize(), 2);
    ASSERT_EQ(greaterThanOrEqualList->getSize(), 3);

    delete lessThanList;
    delete greaterThanOrEqualList;
}
TEST(ListTest, QuicksortTest) 
{
    IntList list;
    list.push_back(3);
    list.push_back(1);
    list.push_back(5);
    list.push_back(2);
    list.push_back(4);

    IntList* sortedList = IntList::quicksort(&list);

    ASSERT_EQ(sortedList->getSize(), 5);
    ASSERT_EQ(sortedList->front(), 1);
    ASSERT_EQ(sortedList->back(), 5);

    delete sortedList;
}

