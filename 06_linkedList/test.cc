// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int partition(int arr[], int be, int en){
    if (be > en) return -1;

    int pivot = arr[en];
    int idx = be;

    while(be < en){
        if (arr[be] < pivot){
            ++be;
            continue;
        }
        if ()
    }
}

void quickSort(int arr[], int be, int en) {
    if (be >= en) return;
    int i = partition(arr, be, en);

    quickSort(arr, 0, i - 1);
    quickSort(arr, i + 1, en);
}

int main() {
    int arr[10];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i];
    }
}