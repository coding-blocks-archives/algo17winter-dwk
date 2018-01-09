#include "tree.h"
#include <iostream>
using namespace std;

int height(TreeNode* root) {
    if (!root) return 0;

    int leftHt = height(root->left);
    int rightHt = height(root->right);
    return max(leftHt, rightHt) + 1;
}


TreeNode*  mirror(TreeNode* root) {
    if (!root) {
        return NULL;
    }

    TreeNode* tmp = root->left;
    root->left = mirror(root->right);
    root->right = mirror(tmp);
    return root;
}


void printAtLevelK(TreeNode* root, int k) {
    if (!root) return;

    if (k == 1) {
        cout << root->data << " ";
        return;
    }

    printAtLevelK(root->left, k - 1);
    printAtLevelK(root->right, k - 1);
}

int diameter(TreeNode* root) {
    if (!root) return 0;

    int leftDia = diameter(root->left);
    int rightDia = diameter(root->right);

    int curDia = height(root->left) + height(root->right) + 1;
    return max(max(leftDia, rightDia), curDia);
}

class Pair {
public:
    int height;
    int dia;
};

Pair diameterOpt(TreeNode* root) {
    if (!root) {
        Pair p;
        p.height = 0;
        p.dia = 0;
        return p;
    }

    Pair leftAns = diameterOpt(root->left);
    Pair rightAns = diameterOpt(root->right);

    Pair cur;
    cur.height = max(leftAns.height, rightAns.height) + 1;
    cur.dia = max(max(leftAns.dia, rightAns.dia),
                  leftAns.height + rightAns.height + 1);
    return cur;
}

class Pair2 {
public:
    int height;
    bool isBal;
    Pair2(int x, bool y) {
        height = x;
        isBal = y;
    }
};

#include <cmath>    // interview hack
Pair2 isHtBal(TreeNode* root) {
    if (!root) {
        return Pair2(0, true);
    }

    Pair2 lt = isHtBal(root->left);
    Pair2 rt = isHtBal(root->right);
    Pair2 curAns(0, false);

    bool isRootBal = std::abs(lt.height - rt.height) <= 1;

    curAns.isBal = isRootBal && lt.isBal && rt.isBal;
    curAns.height = max(lt.height, rt.height) + 1;
    return curAns;
}

void printLeafPaths(TreeNode* root, vector<TreeNode*>& v){
    if (!root){
        return;
    }

    if (root->left == NULL && root->right == NULL){
        // print vector
        v.push_back(root);
        for(int i = 0; i < v.size(); ++i){
            cout << v[i]->data << " ";
        }
        v.pop_back();
        cout << endl;
        return ;
    }

    v.push_back(root);
    printLeafPaths(root->left, v);
    printLeafPaths(root->right, v);
    v.pop_back();
}


int main () {
    TreeNode* root = levelInput();
    levelOutput(root);
    cout << "==================" << endl;

    // int ht = height(root);
    // cout << ht;

    // root = mirror(root);

    // int k; cin >> k;
    // printAtLevelK(root, k);

    // Pair ans = diameterOpt(root);
    // cout << ans.dia << " " << ans.height;

    // Pair2 ans = isHtBal(root);
    // cout << ans.height << " " << ans.isBal;

    vector<TreeNode*> v;
    printLeafPaths(root, v);


}