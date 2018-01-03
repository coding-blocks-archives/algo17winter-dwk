// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int* foo(){
    // int x = 10;
    // return &x;

    int* ptr = new int;
    *ptr = 10;
    ptr = 0;
    // return ptr;
}

int main(){
    int * y = foo();
    cout << y << endl;
    cout << *y << endl;
}