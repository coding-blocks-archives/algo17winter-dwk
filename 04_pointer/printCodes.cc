// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;


void printCodes(char numStr[], int be, char decision[], int i){
    if (numStr[be] == '\0'){
        decision[i] = '\0';
        cout << decision << endl;
        return;
    }


    int curDig = numStr[be] - '0';  //'1'-->1
    char curChar = 'a' + curDig - 1;

    decision[i] = curChar;
    printCodes(numStr, be + 1, decision, i + 1);

    if (numStr[be + 1] == '\0') return;

    int nextDig = numStr[be + 1] - '0'; //'2' --> 2
    int curNum = curDig * 10 + nextDig; // 1,2--> 12
    
    if (curNum > 26) return;

    char char2Dig = 'a' + curNum - 1;

    decision[i] = char2Dig;
    printCodes(numStr, be + 2, decision, i + 1);



}


int main(){
    char numStr[10];
    cin >> numStr;

    char decision[10];

    printCodes(numStr, 0, decision, 0);   
}