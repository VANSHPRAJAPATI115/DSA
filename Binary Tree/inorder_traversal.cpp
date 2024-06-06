#include <iostream>
#include <queue>
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

void Inorder(node *root){
    if(root == NULL){
        return ;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);

}

int main() {
    node* root = NULL;
    root = buildTree();
    cout<<"printing inorder traversal level"<<endl;
    Inorder(root);
    return 0;
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1