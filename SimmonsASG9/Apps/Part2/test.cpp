#include "pch.h"
#include "HASHTab2.h"
using namespace std;
struct Record
{
    int key;
    string data;
};


int hashFunction(const Record& record)
{
    return record.key;
}
int sampleHashKey2(const int& entry) 
{
    return entry;
}
void populateTable(Table<Record, 10, hashFunction>& table)
{
    Record records[] =
    {
        {1, "Record1"},
        {2, "Record2"},
        {11, "Record11"},
        {12, "Record12"},
        {21, "Record21"}
    };

    for (const auto& record : records) 
    {
        table.insert(record);
    }
}



TEST(TableTest, Insertion)
{
    Table<Record, 10, hashFunction> table;
    Record record = { 1, "Record1" };

    table.insert(record);

    EXPECT_TRUE(table.isPresent(1));
}


TEST(TableTest, Removal)
{
    Table<Record, 10, hashFunction> table;
    populateTable(table);

    table.remove(2);

    EXPECT_FALSE(table.isPresent(2));
}


TEST(TableTest, Find)
{
    Table<Record, 10, hashFunction> table;
    populateTable(table);

    bool found = false;
    Record result;

    table.find(11, found, result);

    EXPECT_TRUE(found);
    EXPECT_EQ(result.key, 11);
    EXPECT_EQ(result.data, "Record11");
}

TEST(TableTest, SizeAndCapacity)
{
    Table<Record, 10, hashFunction> table;
    populateTable(table);

    EXPECT_EQ(table.size(), 10);
}


TEST(TableTest, IsPresent)
{
    Table<Record, 10, hashFunction> table;
    populateTable(table);

    EXPECT_TRUE(table.isPresent(12));
    EXPECT_FALSE(table.isPresent(99));
}

TEST(TableTest, QuadraticProbeInserts) 
{
    Table<Record, 10, hashFunction> table;
    size_t index = 0;
    table.insert({ 12, "Record14" });
    EXPECT_EQ(table.isPresent(10), true);
    table.insert({ 31, "Record26" });
    EXPECT_EQ(table.isPresent(20), true);
    EXPECT_EQ(table.isPresent(30), true);
}

TEST(TableTest, TestSecondHash) 
{
    Table<int, 10, sampleHashKey2> table1;
    struct TestCase 
    {
        int key;
        int i;
        size_t expectedResult;
    };

    vector<TestCase> testCases = 
    {
        {10, 1, 7},   
        {10, 2, 14},   
        {15, 1, 7},   
        {15, 2, 14},   
        {21, 1, 7},    
        {0, 1, 7},     
        {5, 1, 14}     
    };
    for (const auto& testCase : testCases) 
    {
        size_t result = table1.secondHash(testCase.key, testCase.i);
        EXPECT_EQ(result, testCase.expectedResult);
    }
}