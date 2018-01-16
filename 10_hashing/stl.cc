// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// void mySort(container, be, en){
//     // for all elemenets from [be, en)
//     // do a comparsion between 2 elements
//     // if (container[be] > container[en]){
//     // if (compareFunct(container[be], container[en])){
//     // swap etc...

// }


// void mySort(containerBe, containerEn, T obj){
// void mySort(containerBe, containerEn, bool (*foo)(int x, int y)){
//     // if (foo(x, y));
//     if (obj(x, y)){ // obj.operator(x, y)

//     }

//     string s;
//     s = s1 + s2; // s = s1.operator+(s2);
// }


bool compareFunction(int x, int y){
    // whether x should come before y in the final answer
    // (2, 3) --> false
    // (3, 2) --> true
    return x > y;
}


class Elephant{
public:
    bool operator()(const int& x, const int& y){
        return x > y;
    }
};

int main(){
    // list<int> l;    //sort 

    vector<int> v;
    v.push_back(2);   
    v.push_back(100);   
    v.push_back(1);  

    Elephant E;
    // sort(v.begin(), v.end(), compareFunction);
    sort(v.begin(), v.end(), E);
    cout << v[0] << v[1] << v[2];
}