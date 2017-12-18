// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void printValues(int startVal, int nValues) {
    for (int ithValue = 1; ithValue <= nValues; ++ithValue) {
        cout << startVal;
        // if (startVal == 0) {
        //     startVal = 1;
        // } else {
        //     startVal = 0;
        // }
        startVal = 1 - startVal;
    }
}

void togglePattern(int N) {
    for (int curRow = 1; curRow <= N; ++curRow) {
        int startVal = (curRow % 2 == 1) ? 1 : 0 ;
        
        // if (curRow % 2 == 1) {
        //     startVal = 1;
        // } else {
        //     startVal = 0;
        // }

        // print curRow values
        printValues(startVal, curRow);
        cout << endl;
    }
}


int main() {
    int N;
    cin >> N;

    togglePattern(N);
}