#include <iostream>
using namespace std;

class Node {
   public:
    int val;
    Node* left = NULL;
    Node* right = NULL;
    Node(int data) { val = data; }
};

void inorder(Node* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->val << " ";
    inorder(node->right);
}

void preorder(Node* node) {
    if (!node) return;
    cout << node->val << " ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node* node) {
    if (!node) return;
    postorder(node->left);
    preorder(node->right);
    cout << node->val << " ";
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    inorder(root);
    cout << "\n";
    preorder(root);
    cout << "\n";
    postorder(root);
    return 0;
}