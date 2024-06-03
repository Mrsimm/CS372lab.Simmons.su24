//Troy Simmons
//CS372
#include <iostream>
#include <vector>
#include "SImmonsASG3P1.h"
using namespace std;
template <typename Thing>
class BagWR {
private:
    List<Thing> bagContents;
    List<int> Receipts;
public:
    int recipt = 0;
    int bagSize = 0;
    void insert(Thing aThing)
    {
        bagContents.push_back(aThing);
        bagSize++;
        Receipts.push_back(recipt++);
    };

    void ListRecipts()
    {
        cout << "The Items are ";
        bagContents.printTheList();
        cout << "The receipt numbers are ";
        Receipts.printTheList();
        cout << endl;
    }
    Thing& Back_pop()
    {
        Thing aThing;
        if (bagContents.size() > 0)
        {
            aThing = bagContents[bagSize - 1];
            bagSize--;
            cout << Receipts.back() << " was removed!" << endl;
            Receipts.pop_back();
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
        return bagContents.count(aThing);
    }
};