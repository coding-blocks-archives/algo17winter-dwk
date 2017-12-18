// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;

    for(int curLine = N; curLine > 0; --curLine){
        // print A B C D E
        char c = 'A';
        for(int ithVal = 1; ithVal <= curLine; ++ithVal){
            cout << c;
            c = c + 1;
        }

        // c = E
        for(int ithVal = 1; ithVal <= curLine; ++ithVal){
            c = c - 1;
            cout << c ;
        }
        
        cout << endl;
    }   
}