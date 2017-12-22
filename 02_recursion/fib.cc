// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int fib(int n){
    if (n <= 0) return 0;
    if (n == 1) return 1;

    return fib(n - 1) + fib(n - 2);
}


int fibIter(int n){
    if (n == 0 || n == 1) return n;

    int prev = 1;
    int superPrev = 0;

    int cur = prev + superPrev;

    for(int i = 2; i <= n; ++i){
        int tmp = cur;
        cur = prev + superPrev;
        superPrev = prev;
        prev  = tmp;
    }
    return cur;
}


int main(){
  int n;
  cin >> n;
  int ans = fibIter(n);
  cout << ans;   
}