// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> v;
    int n;  // no of elements in the heap

    int parent(int i) { return i >> 1; }
    int left(int i) { return (i << 1); }
    int right(int i) { return (i << 1) + 1; }

    void heapify(int idx){
        int pos = idx;

        if (left(idx) <= n && v[left(idx)] > v[pos]){
            pos = left(idx);
        }

        if (right(idx) <= n && v[right(idx)] > v[pos]){
            pos = right(idx);
        }

        if (pos != idx){
            swap(v[pos], v[idx]);
            heapify(pos);
        }
    }

public:
    Heap() {
        v.push_back(-1);
        n = 0;
    }

    bool empty() {
        return n == 0;
    }

    void push(int d) {
        v.push_back(d);
        ++n;

        int idx = n;
        while(idx > 1 && v[parent(idx)] < v[idx]){
            swap(v[parent(idx)], v[idx]);
            idx = parent(idx);
        }
    }

    void pop(){
        if (n == 0) return;

        swap(v[1], v[n]);
        v.pop_back();
        --n;
        heapify(1);

    }

    int top(){
        if (empty()) return -1;
        return v[1];
    }

};


int main() {
    Heap H;
    H.push(1);
    H.push(2);
    H.push(3);
    cout << H.top() <<" "; H.pop();
    cout << H.top() <<" "; H.pop();
    cout << H.top() <<" "; H.pop();
    cout << H.top() <<" "; H.pop();

}