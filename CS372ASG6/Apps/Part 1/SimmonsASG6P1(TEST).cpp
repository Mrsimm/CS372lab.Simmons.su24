#include "pch.h"
#include "SimmonsASG6P1.h"
TEST(ListTest, PushFrontTest) {
    List<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    ASSERT_EQ(list.getSize(), 3);
    ASSERT_EQ(list.front(), 1);
}

TEST(ListTest, PushBackTest) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    ASSERT_EQ(list.getSize(), 3);
    ASSERT_EQ(list.back(), 3);
}

TEST(ListTest, PopFrontTest) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.pop_front();
    ASSERT_EQ(list.getSize(), 2);
    ASSERT_EQ(list.front(), 2);

    list.pop_front();
    ASSERT_EQ(list.getSize(), 1);
    ASSERT_EQ(list.front(), 3);

    list.pop_front();
    ASSERT_TRUE(list.empty());
}

TEST(ListTest, PopBackTest) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.pop_back();
    ASSERT_EQ(list.getSize(), 2);
    ASSERT_EQ(list.back(), 2);

    list.pop_back();
    ASSERT_EQ(list.getSize(), 1);
    ASSERT_EQ(list.back(), 1);

    list.pop_back();
    ASSERT_TRUE(list.empty());
}

TEST(ListTest, CopyConstructorTest) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    List<int> listCopy = list;

    ASSERT_EQ(listCopy.getSize(), list.getSize());
    ASSERT_EQ(listCopy.front(), list.front());
    ASSERT_EQ(listCopy.back(), list.back());
}
