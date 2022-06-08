#include <iostream>
#include <stack>
#include <vector>
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

void postorder(Node* root) {
    stack<Node*> st1, st2;
    st1.push(root);
    while (!st1.empty()) {
        Node* node = st1.top();
        st1.pop();
        st2.push(node);
        if (node->left) st1.push(node->left);
        if (node->right) st1.push(node->right);
    }

    // print the inorder by LIFO of stack st2
    cout << "ss\n";
    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

vector<int> postOrderTrav(Node* curr) {
    vector<int> postOrder;
    if (curr == NULL) return postOrder;

    stack<Node*> s1;
    stack<Node*> s2;
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

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    // preorder(root);
    // cout << "\n";
    // inorder(root);
    // cout << "\n";
    postorder(root);
    return 0;
}