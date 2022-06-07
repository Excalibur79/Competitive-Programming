#include <iostream>
using namespace std;

class Node {
   public:
    int val;
    Node* left = NULL;
    Node* right = NULL;
    Node(int data) { val = data; }
};

int checkBalanced(Node* node) {
    if (!node) return 0;
    int lh = checkBalanced(node->left);
    int rh = checkBalanced(node->right);
    if (lh == -1 || rh == -1) return -1;
    if (abs(lh - rh) > 1) return -1;
    return max(lh, rh) + 1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    int ans = checkBalanced(root);
    ans == -1 ? cout << "Not Balanced" << endl : cout << "Balanced!" << endl;
    return 0;
}