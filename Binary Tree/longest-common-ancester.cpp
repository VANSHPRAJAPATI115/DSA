#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree() {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }

    node* root = new node(data);
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree();
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree();

    return root;
}

class Solution {
public:
    node* lowestCommonAncestor(node* root, node* p, node* q) {
        if (root == NULL) {
            return NULL;
        }
        if (root == p || root == q) {
            return root;
        }
        
        node* leftAns = lowestCommonAncestor(root->left, p, q);
        node* rightAns = lowestCommonAncestor(root->right, p, q);
        
        if (leftAns != NULL && rightAns != NULL) {
            return root;
        } else if (leftAns != NULL) {
            return leftAns;
        } else {
            return rightAns;
        }
    }
};

int main() {
    node* root = NULL;
    root = buildTree();

    Solution sol;

    // Assuming you want to find LCA of nodes with data values `p_data` and `q_data`
    int p_data, q_data;
    cout << "Enter the value of node p: ";
    cin >> p_data;
    cout << "Enter the value of node q: ";
    cin >> q_data;

    node* p = new node(p_data); // Normally you should find the actual nodes in the tree
    node* q = new node(q_data); // Here we just create new ones for simplicity

    node* lca = sol.lowestCommonAncestor(root, p, q);

    if (lca != NULL) {
        cout << "Lowest Common Ancestor is: " << lca->data << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    return 0;
}
