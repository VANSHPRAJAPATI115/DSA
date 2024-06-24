#include <iostream>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;

        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        return root;
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

    // Example usage of lowestCommonAncestor function
    TreeNode* p = new TreeNode(2); // Create TreeNode with value 2
    TreeNode* q = new TreeNode(8); // Create TreeNode with value 8
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    if (lca != NULL) {
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    return 0;
}
