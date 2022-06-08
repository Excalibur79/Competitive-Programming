#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

vector<int> postOrderTrav(node* curr) {
    vector<int> postOrder;
    if (curr == NULL) return postOrder;

    stack<node*> s1;
    stack<node*> s2;
    s1.push(curr);
    while (!s1.empty()) {
        curr = s1.top();
        s1.pop();
        s2.push(curr);
        if (curr->left != NULL) s1.push(curr->left);
        if (curr->right != NULL) s1.push(curr->right);
    }
    while (!s2.empty()) {
        postOrder.push_back(s2.top()->data);
        s2.pop();
    }
    return postOrder;
}

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int main() {
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(8);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    vector<int> postOrder;
    postOrder = postOrderTrav(root);

    cout << "The postOrder Traversal is : ";
    for (int i = 0; i < postOrder.size(); i++) {
        cout << postOrder[i] << " ";
    }
    return 0;
}