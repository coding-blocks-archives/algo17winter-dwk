// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int memo[100];  // global

int fib(int n){
    if (n == 0 || n == 1){
        return n;
    }

    if (memo[n] != -1){
        return memo[n];
    }

    // computation
    int ans = fib(n - 1) + fib(n - 2);
    memo[n] = ans;
    return ans;
}


int minSteps(int n){
    if (n <= 0){
        const int inf = 1e6;
        return inf;
    }
    if (n == 1){
        return 0;
    }

    int ans = 1e6;

    int op1 = n - 1;
    ans = min(ans, minSteps(op1));

    if (n % 2 == 0){
        ans = min(ans, minSteps(n / 2));
    }

    if (n %  3 == 0){
        ans = min(ans, minSteps(n / 3));
    }

    return ans + 1;

}

int main(){
    int n;
    cin >> n;

    // clear the memopad
    for(int i = 0; i <= n; ++i) memo[i] = -1;

    int ans  = fib(n);
    cout << ans;
    
}