// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include "tree.h"
using namespace std;

TreeNode* insertIntoBST(TreeNode* root, int d){
    if (root == NULL){
        root = new TreeNode(d);
        return root;
    }

    if (d > root->data){
        // insert into the right
        root->right = insertIntoBST(root->right, d);
        return root;
    }

    root->left = insertIntoBST(root->left, d);
    return root;
}

TreeNode* createBST(){
    int x;
    TreeNode * root = NULL;
    while(true){
        cin >>x;
        if (x == -1){
            // end of input
            return root;
        }

        root = insertIntoBST(root,x);
    }
}

bool isBst(TreeNode* root, int minVal, int maxVal){
    if (root == NULL) return true;

    return (
        root->data >= minVal && root->data <= maxVal &&
        isBst(root->left, minVal, root->data) &&
        isBst(root->right, root->data, maxVal)
        );
}

int main(){
    // TreeNode* root = createBST();
    // levelOutput(root);
    

    TreeNode* root = levelInput();  // binary Tree
    const int inf = (int)1e6;
    cout << isBst(root, -inf, inf);
}