// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

TreeNode* createTree() {
    int x;
    cin >> x;
    if (x == -1) return NULL;

    TreeNode* root = new TreeNode(x);
    cout << "Enter the left child of " << x << " ";
    root->left = createTree();
    cout << "Enter the right child of " << x << " ";
    root->right = createTree();
    return root;
}

void inOrder(TreeNode* root) {
    if (root == NULL) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}


TreeNode* levelInput() {
    int x;
    cin >> x;
    if (x == -1) return NULL;

    TreeNode* root = new TreeNode(x);   // origin
    queue<TreeNode*> q;
    q.push(root);

    while (q.empty() == false) {
        TreeNode* curParent = q.front();
        q.pop();

        // cout << "Enter the left child of " << curParent->data << " ";
        cin >> x;
        if (x != -1) {
            curParent->left = new TreeNode(x);
            q.push(curParent->left);
        }

        // cout << "Enter the right child of " << curParent->data << " ";
        cin >> x;
        if (x != -1) {
            curParent->right = new TreeNode(x);
            q.push(curParent->right);
        }
    }
    return root;
}

void levelOutput(TreeNode* root) {
    if (root == NULL) return ;

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();

        if (cur == NULL) {
            // end of the level
            cout << endl;
            if (!q.empty()) q.push(NULL);
            continue;
        }

        cout << cur->data << " ";

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}



int main() {
    // TreeNode* root = createTree();
    // inOrder(root);

    TreeNode* root = levelInput();
    // inOrder(root);
    levelOutput(root);
}