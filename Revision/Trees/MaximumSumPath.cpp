#include <limits.h>

#include <iostream>
using namespace std;

int maxSum = INT_MIN;

class Node {
   public:
    int val;
    Node* left = NULL;
    Node* right = NULL;
    Node(int data) { val = data; }
};

int maximumSumPath(Node* node) {
    if (!node) return 0;
    int leftSum = max(0, maximumSumPath(node->left));
    int rightSum = max(0, maximumSumPath(node->right));
    maxSum = max(maxSum, node->val + leftSum + rightSum);
    return node->val + max(leftSum, rightSum);
}

int main() {
    Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    maximumSumPath(root);
    cout << maxSum << endl;
    return 0;
}