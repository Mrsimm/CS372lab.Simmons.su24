#include "pch.h"
#include "TableforFinal.h"
template <class RecordType>
struct TestData 
{
    int key;

};


class TableTest : public ::testing::Test 
{
protected:
    void SetUp() override
    {
       
    }

    void TearDown() override 
    {
    
    }

  
};

TEST_F(TableTest, InsertAndFind)
{
    Table<TestData> table;
    TestData entry1 = { 100 };
    TestData entry2 = { 200 };

    table.insert(entry1);

    bool found;
    TestData result;
    table.find(entry1.key, found, result);
    EXPECT_TRUE(found);
    EXPECT_EQ(result.key, entry1.key);

    table.insert(entry2);
    table.find(entry2.key, found, result);
    EXPECT_TRUE(found);
    EXPECT_EQ(result.key, entry2.key);
}

TEST_F(TableTest, Remove) 
{
    Table<TestData> table;
    TestData entry = { 100 };

    table.insert(entry);

    table.remove(entry.key);

    bool found;
    TestData result;
    table.find(entry.key, found, result);
    EXPECT_FALSE(found);
}

TEST_F(TableTest, IsPresent) 
{
    Table<TestData> table;
    TestData entry = { 100 };

    table.insert(entry);

    EXPECT_TRUE(table.isPresent(entry.key));

    table.remove(entry.key);

    EXPECT_FALSE(table.isPresent(entry.key));
}

