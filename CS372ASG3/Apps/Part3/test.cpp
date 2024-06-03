#include "pch.h"
#include "SimmonsASG3P3.h"
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(ListTest, ConstructorTest)
{
    List<int> list;
    EXPECT_TRUE(list.empty());
}

TEST(ListTest, PushTest)
{
    List<int> Lis;
    Lis.push_front(5);
    EXPECT_EQ(Lis.front(), 5);
    Lis.push_back(10);
    EXPECT_EQ(Lis.back(), 10);
}
TEST(ListTest, PopTest)
{
    List<int> Lis;
    Lis.pop_back();
    Lis.pop_back();
    EXPECT_TRUE(Lis.empty());
}
TEST(ListTest, DestructorTest)
{
    List<int>* Lis = new List<int>();
    Lis->push_back(5);
    delete Lis;
}
