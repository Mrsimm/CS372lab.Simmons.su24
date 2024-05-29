//Troy Simmons
//CS372

#include <iostream>
#include <vector>
#include "pch.h"
using namespace std;





template <typename Thing>
class BagWR {
private:
    vector<Thing> bagContents;
    vector<Thing> Recipts;
public:
    int recipt = 0;
    int bagSize = 0;
    void insert(Thing aThing)
    {
        bagContents.push_back(aThing);
        bagSize++;
        Recipts.push_back(recipt++);
    };

    void ListRecipts()
    {
        cout << "The Items are ";
        for (int i = 0; i <= Recipts.size() - 1; i++)
        {
            cout << bagContents[i] << ", ";
        }
        cout << "The recipt numbers are ";
        for (int i = 0; i <= Recipts.size() - 1; i++)
        {
            cout << Recipts[i] << ", ";
        }
        cout << endl;

    }
    Thing& pop()
    {
        Thing aThing;
        if (bagContents.size() > 0)
        {
            aThing = bagContents[bagSize - 1];
            bagSize--;
            cout << Recipts.back() << " was removed!" << endl;
            Recipts.pop_back();
            return aThing;
        }
        else
        {
            cout << "Cant pop an empty bag!" << endl;
        }
        return aThing;
    }
    int Size()
    {
        return bagSize;
    }
    int count(Thing aThing)
    {
        int bagCount = 0;
        for (int i = 0; i < bagSize; i++)
        {
            if (bagContents[i] == aThing)
            {
                bagCount++;
            }
        }
        return bagCount;
    }
};

TEST(TestCaseName, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

TEST(VectorTest, InitiallyEmpty)
{
    BagWR<int> BAG;
    EXPECT_EQ(BAG.Size(), 0);
    EXPECT_EQ(BAG.count(42), 0);
}
TEST(VectorTest, AddElement)
{
    BagWR<int> BAG;
    BAG.insert(1);;
    EXPECT_EQ(BAG.Size(), 1);
    BAG.insert(2);
    EXPECT_EQ(BAG.Size(), 2);
}

TEST(VectorTest, RemoveElement)
{
    BagWR<int> BAG;
    BAG.insert(42);
    BAG.pop();
    EXPECT_EQ(BAG.Size(), 0);
}