
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<char> steak;
    string strings;
    cout << "Enter a string: ";
    cin >> strings;
    for (char c : strings)
    {
        steak.push(c);
    }
    while (!steak.empty())
    {
        char currentChar = steak.top();
        if (currentChar == '(')
        {
            while (!steak.empty())
            {
                char currentChar = steak.top();
                if (currentChar == ')')
                {
                    cout << "Matching parentesis found" << endl;
                    steak.pop();
                }
                else if (currentChar != ')')
                {
                    steak.pop();
                }
                else if (steak.empty())
                {
                    cout << "No matching parenthesis found!" << endl;
                    steak.pop();
                }
            }
        }
        steak.pop();

    }
}





