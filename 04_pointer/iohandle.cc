// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    // char a1[10];
    // cin >> a1;
    // cout << a1 << endl;

    // char a2[10];
    // cin >> a2;
    // cout << a2 << endl;;

    char arr[10];
    cin >> arr;
    cout << "cin " << cin << endl;

 
    int x;
    cin >> x;
    cout << "cin " << cin << endl;
    cin.clear();     //reset

    cout << "X" << arr << "X" << endl;
    cout << "X" << x << "X" << endl;

    cin >> arr ;
    cout << "cin " << cin << endl;
    cout << "X" << arr << "X" << endl;

}