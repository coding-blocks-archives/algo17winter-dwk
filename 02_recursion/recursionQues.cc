// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void printInc(int n) {  // prints 1...n with one space after every no
    if (n == 0) return;

    printInc(n - 1);    // 1 2 3 4
    cout << n << " " ;
}


int power(int x, int p) {
    if (p <= 0) {
        return 1;
    }

    if (p % 2 == 0) {
        int halfPower = power(x, p / 2);    // 4 ^ 10
        return halfPower * halfPower;
    }

    return power(x, p - 1) * x; // 4^ 9 = 4^ 8 * 4
}

void display(int arr[], int n) {
    // displays an array arr with n elements with a preceding space
    if (n <= 0) return;

    display(arr, n - 1);
    cout << " " << arr[n - 1];  // idx
}


void display2(int arr[], int be, int en) {

    if (be > en) return;

    cout << arr[be] << " ";
    display2(arr, be + 1, en);

}

void displayRev(int arr[], int be, int en) {
    if (be > en) return;

    cout << arr[en] << " ";
    displayRev(arr, be , en - 1);


}

int largestPos(int arr[], int be, int en) {
    if (be > en) {
        return -1;
    }

    int posInRemArr = largestPos(arr, be + 1, en);

    if (arr[be] > arr[posInRemArr]) {
        return be;
    } else {
        posInRemArr;
    }
}

void inputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

// find element in arr
int findElement(int arr[], int be, int en, int elementToSearch) {
    if (be > en) {
        return  -1;
    }

    if (arr[be] == elementToSearch) {
        return be;
    }

    return findElement(arr, be + 1, en, elementToSearch);
}


// bubble sort
int cnt = 0;
void bubbleSort(int arr[], int be, int en) {
    // ++cnt;
    if (be >= en) {
        return ;
    }
    // i have ensured that I have atleast 2 elements
    bubbleSort(arr, be + 1, en);
    if (arr[be] > arr[be + 1]) {
        swap(arr[be], arr[be + 1]);
        bubbleSort(arr, be + 1, en);
    }
}

bool isSorted(int arr[], int be, int en) {
    if (be >= en) {
        return true;
    }

    // bool cur = arr[be] < arr[be + 1];
    // if (cur == false) return false;

    // bool rem = isSorted(arr, be + 1, en);

    // return cur && rem;

    return (arr[be] < arr[be + 1]) && isSorted(arr, be + 1, en);
}

void printDig(int digit) {
    switch (digit) {
    case 0 :
        cout << "zero";
        break;
    case 1 :
        cout << "one";
        break;
    case 2 :
        cout << "two";
        break;
    case 4 :
        cout << "four";
        break;
    case 8 :
        cout << "eight";
        break;
    }
}


void printNum(int num) {
    if (num <= 0) return ;

    printNum(num / 10); // 204

    printDig(num % 10); // 8
    cout << " ";

}

int binarySearch(int arr[], int be, int en, int elementToSearch) {
    if (be > en) return -1;

    int mid = (be + en ) / 2;

    if (arr[mid] == elementToSearch) return mid;

    if (arr[mid] > elementToSearch) {
        // search in the left
        return binarySearch(arr, be, mid - 1, elementToSearch);
    }

    return binarySearch(arr, mid + 1, en, elementToSearch);
}

void copyArr(int x[], int arr[], int be, int en) {
    while (be <= en) {
        x[be] = arr[be];
        ++be;
    }
}

void mergeSortedArr(int arr[], int i, int ei, int j, int ej) {
    // i = first array
    // j = second array
    // e for end

    // HW : with index manipulation
    const int N = 100;
    int x[N];
    int y[100];
    copyArr(x, arr, i, ei);
    copyArr(y, arr, j, ej);

    int k = i;

    while (i <= ei && j <= ej) {
        if (x[i] < y[j]) {
            arr[k] = x[i];
            ++k;
            ++i;
        } else {
            arr[k] = y[j];
            ++j;
            ++k;
        }
    }

    while (i <= ei) {
        arr[k] = x[i];
        ++i;
        ++k;
    }

    while (j <= ej) {
        arr[k] = y[j];
        ++j;
        ++k;
    }
}


void mergeSort(int arr[], int be, int en) {
    if (be >= en) {
        return;
    }

    int mid = (be + en) / 2;

    mergeSort(arr, be, mid);
    mergeSort(arr, mid + 1, en);

    mergeSortedArr(arr, be, mid, mid + 1, en);
}


int main() {
    int n;
    cin >> n;

    // printInc(n);

    // int p;
    // cin >> p;
    // int ans = power(n, p);
    // cout << ans;

    int arr[100];
    inputArr(arr, n);

    bubbleSort(arr, 0, n - 1);
    display(arr, n);
    cout << cnt << endl;

    // bool ans = isSorted(arr, 0, n - 1);
    // cout << ans;

    // printNum(n);

    // int elementToSearch; cin >> elementToSearch;
    // cout << binarySearch(arr, 0, n - 1, elementToSearch);

    // mergeSort(arr, 0, n - 1);
    // display(arr, n);



}