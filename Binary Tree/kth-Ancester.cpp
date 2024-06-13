#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }

    Node* root = new Node(data);
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree();
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree();

    return root;
}

Node* solve(Node *root, int &k, int node) {
    if (root == NULL)
        return NULL;

    if (root->data == node) {
        return root;
    }

    Node *leftAns = solve(root->left, k, node);
    Node *rightAns = solve(root->right, k, node);

    if (leftAns != NULL && rightAns == NULL) {
        k--;
        if (k <= 0) {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }

    if (leftAns == NULL && rightAns != NULL) {
        k--;
        if (k <= 0) {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }

    return NULL;
}

int kthAncestor(Node *root, int k, int node) {
    Node* ans = solve(root, k, node);
    if (ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}

int main() {
    Node* root = NULL;
    root = buildTree();
    
    int k, node;
    cout << "Enter the value of k: ";
    cin >> k;
    cout << "Enter the node value to find its k-th ancestor: ";
    cin >> node;
    
    int ancestor = kthAncestor(root, k, node);
    if (ancestor == -1)
        cout << "The k-th ancestor does not exist." << endl;
    else
        cout << "The " << k << "-th ancestor of node " << node << " is: " << ancestor << endl;

    return 0;
}
