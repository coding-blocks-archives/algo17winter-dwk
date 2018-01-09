#include "tree.h"
#include <iostream>
using namespace std;

int main (){
    TreeNode* root = levelInput();
    
    int ht = height(root);
    cout << ht;
}