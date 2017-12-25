// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void foo(int twoDPtr[][4]){

}


int main(){
    int mat[2][4];

    // cout << mat[0] << endl;     // first row or an array
    cout << &mat[0][0] << endl;  // add of first cell
    cout << &mat[0] << endl;    // add of the first row

    cout << &mat[0][0] + 1 << endl;
    cout << &mat[0] + 1 << endl;

    // pointer to an array
    int(*ptr)[4] = &mat[0];
    cout << ptr + 1 << endl;

    foo(mat);

}