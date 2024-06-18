#include <iostream>
#include <queue>
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

void Preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);

}

Node* insertIntoBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
    if (data > root->data) {
        root->right = insertIntoBST(root->right, data);
    } else {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

Node* takeInput() {
    Node* root = NULL;
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
    return root;
}

int main() {
    Node* root = NULL;
    cout << "Enter the data (enter -1 to stop):" << endl;
    root = takeInput();
    cout << "Printing tree: " << endl;
    Preorder(root);

    return 0;
}
