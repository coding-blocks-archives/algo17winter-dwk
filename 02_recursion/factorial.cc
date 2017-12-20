// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int fact(int n){
    if (n <= 0) return 1;

    int smallFact = fact(n - 1);
    int ans = n * smallFact;
    return ans;

    // return n * fact(n - 1);
}

int main(){
    int n;
    cin >> n;

    int ans = fact(n);
    cout << ans;   
}