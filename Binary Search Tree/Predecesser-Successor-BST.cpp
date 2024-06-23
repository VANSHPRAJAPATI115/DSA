#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

pair<int, int> predecessorSuccessor(TreeNode *root, int key) {
    TreeNode *temp = root;
    int pred = -1;
    int succ = -1;

    // Find the key node
    while (temp != NULL && temp->data != key) {
        if (temp->data > key) {
            succ = temp->data;
            temp = temp->left;
        } else {
            pred = temp->data;
            temp = temp->right;
        }
    }

    // If the key is not present in the tree
    if (temp == NULL) {
        return make_pair(-1, -1);
    }

    // Find the predecessor (max value in the left subtree)
    TreeNode *leftTree = temp->left;
    while (leftTree != NULL) {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // Find the successor (min value in the right subtree)
    TreeNode *rightTree = temp->right;
    while (rightTree != NULL) {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    return make_pair(pred, succ);
}

int main() {
    // Creating a sample BST for testing
    TreeNode *root = new TreeNode(6521171);
    root->left = new TreeNode(5650934);
    root->right = new TreeNode(9278816);
    root->left->left = new TreeNode(899375);
    root->right->left = new TreeNode(8989449);
    root->right->right = new TreeNode(9615950);

    int key = 9278816;
    pair<int, int> result = predecessorSuccessor(root, key);
    cout << "Predecessor: " << result.first << ", Successor: " << result.second << endl;

    return 0;
}
