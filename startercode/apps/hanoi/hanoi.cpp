#include <iostream>
#include <chrono>
using namespace std;

void moveDisks(int, int, int, int);
void printIt(int , int , int );

int main() {
    const int FROMPEG = 1;
    const int TOPEG = 3;
    const int TEMPPEG = 2;
    const int NUMDISKS = 3;
    auto start = std::chrono::system_clock::now();
    for (auto numdisks: {3,5,6}) {
      cout << "Numdisks: " << numdisks << endl;
      moveDisks(numdisks, FROMPEG, TOPEG, TEMPPEG);
      cout << "Moved " << numdisks << " pegs"
           << " from peg " << FROMPEG
           << " to peg " << TOPEG << endl;
    }
    auto end = std::chrono::system_clock::now();
    auto timespent = end - start;

    cout << timespent.count() / 1000;
}

void moveDisks(int num, int fromPeg, int toPeg, int tempPeg) {
     if (num > 0) {
        moveDisks(num -1, fromPeg, tempPeg, toPeg);
        printIt(num, fromPeg, toPeg);
        moveDisks(num-1, tempPeg, toPeg, fromPeg);
     }
}

void printIt(int disk, int fromPeg, int toPeg) {
  // Do nothing for timing test, but otherwise
  cout<< "Move disk " << disk
      << " from pef " << fromPeg
      << " to peg " << toPeg << endl;
}

