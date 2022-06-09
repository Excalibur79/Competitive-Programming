
#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *left, *right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

void verticalOrderTraversal(auto& verticalHash, Node* node, int col,
                            int level) {
    if (!node) return;
    verticalHash[col][level].insert(node->data);
    verticalOrderTraversal(verticalHash, node->left, col - 1, level + 1);
    verticalOrderTraversal(verticalHash, node->right, col + 1, level + 1);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    map<int, map<int, multiset<int>>> verticalHash;
    verticalOrderTraversal(verticalHash, root, 0, 0);

    for (auto data : verticalHash) {
        cout << data.first << "--->";
        for (auto data2 : data.second) {
            for (int setValue : data2.second) {
                cout << "(" << data2.first << "," << setValue << ") , ";
            }
        }
        cout << "\n";
    }

    return 0;
}