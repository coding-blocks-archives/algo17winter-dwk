// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

double fahrToCel(int fahr) {
    return (5.0 / 9.0 * (fahr - 32));
}

void printFahrCel(int initial, int final, int step) {
    while (initial <= final) {
        double cel = fahrToCel(initial);
        cout << initial << " " << cel << endl;
        initial = initial + step;
    }
}



int main() {
    int initial;
    int final;
    int step;
    cin >> initial >> final >> step;

    printFahrCel(initial, final, step);
}