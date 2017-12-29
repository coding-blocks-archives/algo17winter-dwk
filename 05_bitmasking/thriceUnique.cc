// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void setCnt(int arr[], int num){
    int idx = 0;
     
    while(num){
        if (num & 1) arr[idx] += 1;
        ++idx;
                        // num = num >> 1;
        num >>= 1;      // a = a + 1; a += 1

    }
}

int cnvtToDecimal(int arr[]){
    int ans = 0;
    for(int i = 0; i < 32; ++i){
        ans += arr[i] * (1 << i); // Power func is prohibited
    }
    return ans;
}

int thriceUnique(int n){
    int bitArr[32] = {};

    for(int i = 0; i < n; ++i){
        int curNum;
        cin >> curNum;
        setCnt(bitArr, curNum);
    }

    for(int i = 0; i < 32; ++i){
        bitArr[i] = bitArr[i] % 3;
    }

    int ans = cnvtToDecimal(bitArr);
}



int main(){
    int n;
    cin >> n;
    int ans = thriceUnique(n);
    cout << ans;   
}