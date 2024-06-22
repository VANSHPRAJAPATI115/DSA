#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    bool BST(Node* root, int min, int max) {
        if (root == NULL)
            return true;

        if (root->data > min && root->data < max) {
            bool left = BST(root->left, min, root->data);
            bool right = BST(root->right, root->data, max);
            return left && right;
        } else {
            return false;
        }
    }

    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        return BST(root, INT_MIN, INT_MAX);
    }
};

// Helper function to insert a new node with given key in BST
Node* insert(Node* node, int key) {
    if (node == NULL) return new Node(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    return node;
}

int main() {
    // Create an instance of Solution
    Solution sol;

    // Create a BST
    Node* root = new Node(4);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);
    insert(root, 5);
    insert(root, 7);

    // Check if the tree is a BST
    if (sol.isBST(root)) {
        cout << "The tree is a BST." << endl;
    } else {
        cout << "The tree is not a BST." << endl;
    }

    return 0;
}
