#include <iostream>
#include <fstream>
#include <random>
#include <iostream>
#include <vector>
using namespace std;
class SortTest {
public:
    SortTest() {

    }

    vector<int> testData1 = { 8, 5, 6, 4, 100, 32, 1000 };
    vector<int> testData2;
    vector<std::string> testData3 = { "Tom", "Harry", "Dick", "Ringo", "George", "John", "Paul" };

    int giveMeARandomInt(int start, int end) {
        random_device r;
        default_random_engine eng1(r());
        uniform_int_distribution<int> uniGenerator(start, end);
        return uniGenerator(eng1);

    }
    void fillWithRandomIntegers(std::vector<int>& v, int numberItems) {
        for (int i = 0; i < numberItems; ++i) {
            v[i] = giveMeARandomInt(0, 100000);
        }
    }
};

