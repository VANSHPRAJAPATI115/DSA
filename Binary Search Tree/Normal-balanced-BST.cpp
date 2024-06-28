#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) {
        this->val = d;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int> &in) {
        if (root == NULL) return;

        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

    TreeNode* inorderToBST(int s, int e, vector<int> &in) {
        if (s > e) return NULL;

        int mid = (s + e) / 2;
        TreeNode* root = new TreeNode(in[mid]);
        root->left = inorderToBST(s, mid - 1, in);
        root->right = inorderToBST(mid + 1, e, in);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorderVal;
        inorder(root, inorderVal);
        return inorderToBST(0, inorderVal.size() - 1, inorderVal);
    }
};

void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->val << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

TreeNode* insertIntoBST(TreeNode* root, int data) {
    if (root == NULL) {
        root = new TreeNode(data);
        return root;
    }
    if (data > root->val) {
        root->right = insertIntoBST(root->right, data);
    } else {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

TreeNode* takeInput() {
    TreeNode* root = NULL;
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
    return root;
}

int main() {
    TreeNode* root = NULL;
    cout << "Enter the data (enter -1 to stop):" << endl;
    root = takeInput();
    
    cout << "Printing tree before balancing: " << endl;
    levelOrderTraversal(root);

    Solution sol;
    root = sol.balanceBST(root);

    cout << "Printing tree after balancing: " << endl;
    levelOrderTraversal(root);

    return 0;
}
