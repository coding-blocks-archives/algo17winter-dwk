// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;


void printPrimes(int N);        // function declaration

int main(){
    int N;
    cin >> N;

    printPrimes(N);     // function calling
}

bool isPrime(int n){
    int div = 2;
    while(div < n){
        if (n % div == 0){
            return false;
        }
        ++div;
    }
    return true;
}


void printPrimes(int N){
    // function definiton

    for(int curNum = 2; curNum <= N; ++curNum){
        if (isPrime(curNum) == true){
            cout << curNum << " ";
        }
    }

}