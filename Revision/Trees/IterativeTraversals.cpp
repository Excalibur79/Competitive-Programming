#include <iostream>
#include <stack>
using namespace std;

class Node {
   public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void preorder(Node* root) {
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* curNode = st.top();
        st.pop();
        cout << curNode->data << " ";
        if (curNode->right) st.push(curNode->right);
        if (curNode->left) st.push(curNode->left);
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);
    preorder(root);
    return 0;
}