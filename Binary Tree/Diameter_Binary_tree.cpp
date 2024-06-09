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

int height(node* node) {
    if (node == NULL) {
        return 0;
    }
    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left, right) + 1;
    return ans;
}

int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int op1= diameter(root->left);
    int op2= diameter(root->right);
    int op3= height(root->left)+height(root->right)+1;

    int ans = max(op1, max(op2,op3));
    return ans;
}

int main() {
    node* root = NULL;
    root = buildTree();
    cout << "Diameter of the tree is: " << diameter(root) << endl;
    return 0;
}
