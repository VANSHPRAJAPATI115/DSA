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

class Solution {
public:
    void flatten(Node* root) {
        if (!root) return;

        Node* curr = root;
        while (curr) {
            if (curr->left) {
                Node* rightMost = curr->left;
                while (rightMost->right) {
                    rightMost = rightMost->right;
                }
                rightMost->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};

void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
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
    levelOrderTraversal(root);

    Solution sol;
    sol.flatten(root);
    cout << "Printing flattened tree: " << endl;
    levelOrderTraversal(root);

    return 0;
}
