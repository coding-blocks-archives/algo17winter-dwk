// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int findPeople(double reqProb) {
    // same bday
    const int totalDays = 365;
    int n = 1;
    double calcProb = 1;    // diff bday

    while ((reqProb - (1 - calcProb)) > 1e-100) {
        n = n + 1;
        calcProb *= 1.0 * (totalDays - (n - 1)) / totalDays;    //double
    }
    return n;
}


int main() {
    double p;
    cin >> p;

    int n = findPeople(p);
    cout << n;
}