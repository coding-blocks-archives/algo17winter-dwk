// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void digToAlph(char dig, char arr[]){
    char codes[][10] = {
        "",
        "@#$", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    int idx = dig - '0';
    strcpy(arr, codes[idx]);    // arr = codes[idx];
}


void keypad(char numStr[], int be, char decision[], int i){

    if (numStr[be] == '\0'){
        decision[i] = '\0';
        cout << decision << endl;
        return;
    }

    char alphaCode[5];
    char curDig = numStr[be];
    digToAlph(curDig, alphaCode);

    for(int j = 0; alphaCode[j] != '\0'; ++j){
        decision[i] = alphaCode[j];
        keypad(numStr, be + 1, decision, i + 1);
    }

}


int main(){
    char str[10];
    cin >> str;

    char decision[10] = "";


    keypad(str, 0, decision, 0);   
}