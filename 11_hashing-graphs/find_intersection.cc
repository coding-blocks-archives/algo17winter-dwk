// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;

void inputArr(int a[], int n){
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
}

void  printVector(vector<int>& v){
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
}

vector<int> intersectionArr(int a[], int i, int ei,
                            int b[], int j, int ej){

    vector<int> ans;
    while(i <= ei && j <= ej){
        if (a[i] < b[j]){
            i++;
        }
        else if (b[j] < a[i]){
            ++j;
        } else {
            ans.push_back(a[i]);
            ++i;
            ++j;
        }
    }
    return ans;
}

vector<int> intersectionArr2(int a[], int i, int ei, 
                      int b[], int j, int ej){

    // make a hashmap from array b
    map<int, int> m;
    for(int k = j; k <= ej; ++k){
        int key = b[k];
        int val = b[k];
        m.insert(make_pair(key, val));
    }

    vector<int> ans;
    // seraching
    for(int k = i; k <= ei; ++k){
        // if element in a also exists in b, great an intersection
        int valToSearch = a[k];
        /*if (m[valToSearch] == ???){

        }*/
        if (m.find(valToSearch) != m.end()){
            // i got an iteator which is not equal to the end...it lies within the
            // container
            ans.push_back(valToSearch);
        }
    }
    return ans;
}

int main(){
    int a[10];
    int b[10];
    int n1, n2;
    cin >> n1 >>n2;
    inputArr(a, n1);
    inputArr(b, n2);
    vector<int> ans = intersectionArr2(a, 0, n1 - 1, b, 0, n2-1);
    printVector(ans);   
}