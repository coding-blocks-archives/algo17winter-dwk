# 1 ".\\treeQues.cc"
# 1 "<command-line>"
# 1 ".\\treeQues.cc"
# 1 ".\\tree2.h" 1
# 1 ".\\tree.h" 1


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

    TreeNode* root = new TreeNode(x);
    queue<TreeNode*> q;
    q.push(root);

    while (q.empty() == false) {
        TreeNode* curParent = q.front();
        q.pop();


        cin >> x;
        if (x != -1) {
            curParent->left = new TreeNode(x);
            q.push(curParent->left);
        }


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

            cout << endl;
            if (!q.empty()) q.push(NULL);
            continue;
        }

        cout << cur->data << " ";

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}
# 2 ".\\tree2.h" 2

class SuperNode{
    TreeNode t;
};
# 2 ".\\treeQues.cc" 2
# 1 ".\\tree.h" 1


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

    TreeNode* root = new TreeNode(x);
    queue<TreeNode*> q;
    q.push(root);

    while (q.empty() == false) {
        TreeNode* curParent = q.front();
        q.pop();


        cin >> x;
        if (x != -1) {
            curParent->left = new TreeNode(x);
            q.push(curParent->left);
        }


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

            cout << endl;
            if (!q.empty()) q.push(NULL);
            continue;
        }

        cout << cur->data << " ";

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}
# 3 ".\\treeQues.cc" 2


int main (){

}
