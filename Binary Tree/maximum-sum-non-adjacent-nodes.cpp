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

class Solution{
public:
    pair<int, int> solve(Node* root){
        if(root == NULL){
            return make_pair(0,0);
        }
        
        // Recursively solving for left and right subtrees
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        pair<int, int> res;
        res.first = root->data + left.second + right.second;
        res.second = max(left.first, left.second) + max(right.first, right.second);
        
        return res;
    }
    
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};

int main() {
    Node* root = buildTree();
    
    Solution sol;
    int result = sol.getMaxSum(root);
    cout << "The maximum sum of non-adjacent nodes is: " << result << endl;
    
    return 0;
}
// 1 2 4 -1 -1 -1 3 5 -1 -1 6 -1 -1