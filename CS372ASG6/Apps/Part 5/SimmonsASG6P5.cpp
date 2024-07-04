#include "Dictionary.h"
#include <iostream>
using namespace std;
int main() 
{
    Dictionary<string, int> dict;

    dict.set("one", 1);
    dict.set("two", 2);
    dict.set("three", 3);

    cout << "Value for key 'two': " << dict.get("two") << endl;

    cout << "Keys in dictionary: ";
    for (const auto& key : dict.getKeys()) 
    {
        cout << key << " ";
    }
    cout << endl;

    cout << "Values in dictionary: ";
    for (const auto& value : dict.getValues()) 
    {
        cout << value << " ";
    }
    cout << endl;

    cout << "Value for key 'four': " << dict["four"] << endl; 

    return 0;
}
