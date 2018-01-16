// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int left(int i) {return (i << 1) + 1;}
int right(int i) {return (i << 1) + 2;}
int parent(int i){return (i - 1) >> 1;}

void heapify(int a[], int be, int en){
    int pos = be;
    int i = be;
    if (left(i) <= en && a[left(i)] > a[pos]){
        pos = left(i);
    }

    if (right(i) <= en && a[right(i)] > a[pos]){
        pos = right(i);
    }

    if (pos != i){
        swap(a[pos], a[i]);
        heapify(a, pos, en);
    }
}

void buildHeap(int a[], int be, int en){
    for(int i = parent(en); i >= 0; --i){
        heapify(a, i, en);
    }
}


void heapSort(int a[], int be, int en) {

    buildHeap(a, be, en);

    for(int i = en; i > 0; --i){
        swap(a[0], a[i]);
        heapify(a, 0, i - 1);
    }

}


int main() {
    int arr[100];
    int n; cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    heapSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
}