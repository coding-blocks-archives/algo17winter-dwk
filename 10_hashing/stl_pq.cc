// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
using namespace std;
class Compare{
public:
    bool operator()(int x, int y){
        // shall x come before y
        // x > y --> true
        // x < y --> false
        return x > y;
    }
};


int main(){
    priority_queue<int, vector<int>, Compare> q;  // minHeap

    q.push(2);
    q.push(3);
    q.push(1);
    cout << q.top();   
}