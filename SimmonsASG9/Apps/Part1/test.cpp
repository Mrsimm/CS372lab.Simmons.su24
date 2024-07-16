#include "pch.h"
#include "HashTABLE.h"
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

    for (const auto& record : records) {
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