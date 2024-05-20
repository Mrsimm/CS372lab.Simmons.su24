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
    int numdisks;
    cout << "How many disks: " << endl;
    cin >> numdisks;
    auto start = std::chrono::system_clock::now();
      cout << "Numdisks: " << numdisks << endl;
      moveDisks(numdisks, FROMPEG, TOPEG, TEMPPEG);
      cout << "Moved " << numdisks << " pegs"
           << " from peg " << FROMPEG
           << " to peg " << TOPEG << endl;
   auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> duration = end - start;
int seconds = std::chrono::duration_cast<std::chrono::seconds>(duration).count();
    cout << seconds << " Seconds";
    return 0;
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

