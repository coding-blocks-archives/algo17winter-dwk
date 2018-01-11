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

class PairHT{
public:
    TreeNode* head;
    TreeNode* tail;
    PairHT(TreeNode* h, TreeNode* t){
        head = NULL;
        tail = NULL;
    }
}; 

PairHT convertToLL(TreeNode* root){
    if (!root){
        return PairHT(NULL, NULL);
    }

    PairHT lt = convertToLL(root->left);
    PairHT rt = convertToLL(root->right);
    PairHT cur(NULL, NULL);

    if(lt.head){
        root->left = lt.tail;
        lt.tail->right = root;
        cur.head = lt.head;
    } else{
        cur.head = root;
        root->left = NULL;
    }

    // right subtree
    if (rt.head){
        root->right = rt.head;
        rt.head->left = root;
        cur.tail = rt.tail;
    } else{
        root->right = NULL;
        cur.tail = root;
    }
    return cur;
}

void printLL(TreeNode* head){
    TreeNode* cur = head;
    while(cur){
        if (cur->left) cout << "(" << cur->left->data << ")";
        cout << cur->data;
        if (cur->right) cout << "(" << cur->right->data << ")";
        cout << "<-->";
        cur = cur->right;
    }
    cout << endl;
}

int main(){
    // TreeNode* root = createBST();
    // levelOutput(root);
    

    // TreeNode* root = levelInput();  // binary Tree
    // const int inf = (int)1e6;
    // cout << isBst(root, -inf, inf);


    TreeNode* root = createBST();
    PairHT ans = convertToLL(root);
    printLL(ans.head);

}