// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int findUnique(int n) {
    int curNum;
    int ans = 0;    //sentinel

    for (int i = 0; i < n; ++i) {
        cin >> curNum;
        ans = ans ^ curNum;
    }
    return ans;
}


int main() {
    int n;
    cin >> n;

    int ans = findUnique(n);
    cout << ans;
}