#include <iostream>
#include <climits>
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
    void longestPath(node *root, int len, int sum, int &maxSum, int &maxLen) {
        if (root == NULL) {
            if (len > maxLen) {
                maxLen = len;
                maxSum = sum;
            } else if (len == maxLen) {
                maxSum = max(sum, maxSum);
            }
            return;
        }
        sum = sum + root->data;
        longestPath(root->left, len + 1, sum, maxSum, maxLen);
        longestPath(root->right, len + 1, sum, maxSum, maxLen);
    }

    int sumOfLongRootToLeafPath(node *root) {
        int len = 0;
        int sum = 0;
        int maxSum = INT_MIN;
        int maxLen = 0;
        longestPath(root, len, sum, maxSum, maxLen);
        return maxSum;
    }
};

int main() {
    node* root = NULL;
    root = buildTree();

    Solution sol;
    int result = sol.sumOfLongRootToLeafPath(root);
    cout << "Sum of the longest path from root to leaf: " << result << endl;

    return 0;
}
