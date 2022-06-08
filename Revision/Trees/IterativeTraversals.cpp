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

void inorder(Node* root) {
    stack<Node*> st;
    Node* node = root;
    while (true) {
        if (node) {
            st.push(node);
            node = node->left;
        } else {
            Node* topNode = st.top();
            st.pop();
            cout << topNode->data << " ";
            node = topNode->right;
        }
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
    // preorder(root);
    // cout << "\n";
    inorder(root);
    return 0;
}