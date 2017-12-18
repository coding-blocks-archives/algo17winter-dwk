/*
1
2 3
4 5 6
*/
// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void printPattern(int N){
    int val = 1;

    for(int curLine = 1; curLine <= N; ++curLine){
        for(int ithVal = 1; ithVal <= curLine; ++ithVal){
            cout << val << " ";
            ++val;
        }
        cout << endl;
    }
}

int main(){
    int N;
    cin >> N;
    printPattern(N);   
}
