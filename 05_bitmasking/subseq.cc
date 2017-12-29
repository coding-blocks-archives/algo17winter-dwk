// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void printSub(char arr[], int be, char decision[], int i) {
    if (arr[be] == '\0'){
        decision[i] = '\0';
        cout << decision << endl;
        return; // MUST MUST!!!
    }

    // bc, ""
    printSub(arr, be + 1, decision, i);

    decision[i] = arr[be];
    // bc, "a"
    printSub(arr, be + 1, decision, i + 1);
}


int main() {
    char arr[100];
    cin >> arr;
    char decision[100];

    printSub(arr, 0, decision, 0);
}