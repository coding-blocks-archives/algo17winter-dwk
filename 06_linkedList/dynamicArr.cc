// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int* inputArr(int n){
    // int* arr = new int[n];  // garbage

    int* arr = new int[n];  // initialisation


    for(int i = 0; i < n; ++i){
        // cin >> arr[i];
    }

    return arr;
}

void printArr(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
}

int main(){
    int n;
    cin >> n;
    int* arr = inputArr(n);

    printArr(arr, n);   
}