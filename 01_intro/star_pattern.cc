// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void printStars(int n){
    for(int i = 0; i < n; ++i){
        cout << "*";
    }
}

void printPattern(int n){

    for(int curRow = 1; curRow <= n; ++curRow){
        printStars(curRow);
        cout << " ";

        int nStars = n + 1 - curRow;
        printStars(nStars);
        cout << " ";

        printStars(nStars);
        cout << " ";
        printStars(curRow);
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;

    printPattern(n);   
}