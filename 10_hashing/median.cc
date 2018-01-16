// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

struct compare{
    bool operator()(int x, int y){
        return x > y;
    }
};
// try making them local

priority_queue<int> lft;   // maxheap
priority_queue<int, vector<int>, compare> rgt; // minHeap

void rebalance(){
    if ((int)lft.size() - (int)rgt.size() > 1){
        int x = lft.top();
        lft.pop();
        rgt.push(x);
    } else if (rgt.size() > lft.size()){
        lft.push(rgt.top());
        rgt.pop();
    }
}

void add(int x){
    if (lft.empty() || x <= lft.top()){
        lft.push(x);
    } else {
        rgt.push(x);
    }
    rebalance();
}

double median(){
    if (rgt.size() == lft.size()){
        return (double)(lft.top() + rgt.top()) / 2;
    }
    return lft.top();
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        add(x);
        double ans = median();
        // cout << ans << endl;
        printf("%.1f\n", ans);
    }
}