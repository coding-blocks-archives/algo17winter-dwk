// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int cntBits(int x){
    int cnt = 0;

    while(x != 0){
        int isOne = x & 1;
        if (isOne == 1) ++cnt;
        x = x >> 1;
    }   
    return cnt;
}

int fastCntBits(int x){
    int cnt = 0;
    while(x != 0){
        int isSet = x & (-x);
        if (isSet) ++cnt;   // integers are convertible to bool
        x = x & (~isSet);
    }
    return cnt;
}

int main(){
    int x;
    cin >> x;
    int ans = fastCntBits(x);
    cout << ans;    
}