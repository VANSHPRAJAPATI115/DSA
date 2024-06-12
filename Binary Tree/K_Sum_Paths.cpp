#include <iostream>
#include <vector>
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

class Solution {
    void solve(Node *root, int k, int &count, vector<int> &path) {
        if (root == nullptr) return;

        // Add current node's data to the path
        path.push_back(root->data);

        // Recur for left and right subtrees
        solve(root->left, k, count, path);
        solve(root->right, k, count, path);

        // Check the sums of all sub-paths in the current path
        int sum = 0;
        for (int i = path.size() - 1; i >= 0; i--) {
            sum += path[i];
            if (sum == k) {
                count++;
            }
        }

        // Remove the current node's data from the path before returning
        path.pop_back();
    }

    public:
    int sumK(Node *root, int k) {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
};

int main() {
    Node* root = NULL;
    root = buildTree();

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    Solution sol;
    int result = sol.sumK(root, k);
    cout << "Number of paths with sum " << k << ": " << result << endl;

    return 0;
}
