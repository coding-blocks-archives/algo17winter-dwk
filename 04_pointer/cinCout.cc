// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int arr[10] = {1,2,3,4};
    
    char carr[10] = {'a', 'b', 'c'};   
    char cstr[] = "abc";


    cout << arr << endl;
    cout << (int*)carr << endl;

    // cin >>  arr; // !!! Int address
    cin >> carr ;   // cin knows how to read
    
}