#include <iostream>
#include <vector>
#include <queue>
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
    void inorder(TreeNode* root, vector<int> &inorderVal) {
        if (root == NULL) return;

        inorder(root->left, inorderVal);
        inorderVal.push_back(root->val);
        inorder(root->right, inorderVal);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderVal;
        inorder(root, inorderVal);

        int i = 0;
        int j = inorderVal.size() - 1;

        while (i < j) {
            int sum = inorderVal[i] + inorderVal[j];
            if (sum == k) return true;
            else if (sum > k) j--;
            else i++;
        }
        return false;
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
};

int main() {
    Solution sol;
    TreeNode* root = NULL;
    cout << "Enter the data (enter -1 to stop):" << endl;
    root = sol.takeInput();
    cout << "Printing tree: " << endl;
    sol.levelOrderTraversal(root);

    // Example usage of findTarget function
    int k;
    cout << "Enter the target sum k: ";
    cin >> k;
    if (sol.findTarget(root, k)) {
        cout << "Target sum found in the tree." << endl;
    } else {
        cout << "Target sum not found in the tree." << endl;
    }

    return 0;
}
