// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int xored(int arr[], int n){
    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans ^= arr[i];
    }
    return ans;
}

void twoUnique(int arr[], int n, int& n1, int& n2){
    int xorOfTwoElements = xored(arr,n);   // c xor d

    int setBit = xorOfTwoElements & (-xorOfTwoElements);

    // xor of elements whose setBit is set
    int xorForOneElement = 0;   // after filter
    for(int i = 0; i < n; ++i){
        if (setBit & arr[i]){
            xorForOneElement ^= arr[i];
        }
    }

    n1 = xorForOneElement;
    n2 = xorForOneElement ^ xorOfTwoElements;

}


int main(){
    int n;
    cin >> n;

    int arr[100];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    } 

    int n1, n2;
    twoUnique(arr, n, n1, n2);

    cout << n1 << " " << n2;   
}