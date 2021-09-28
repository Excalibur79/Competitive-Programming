// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
using namespace std;

#define ll long long
//#define int long long int
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
const int MOD = 1e9 + 7;
const ll INF = 1e18;
#define inputarr(arr, n) \
    for (ll i = 0; i < n; i++) cin >> arr[i];
#define printarr(arr, n) \
    for (ll i = 0; i < n; i++) cout << arr[i] << ' ';
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

void takeInput(struct Node *node) {
    bool left, right;
    int data;
    cin >> data;
    cin >> left >> right;
    node = new Node(data);
    if (left) takeInput(node->left);
    if (right) takeInput(node->right);
}

int maxPath = INT_MIN;

int maximumPathSum(struct Node *node) {
    if (!node) return 0;
    int leftSum = max(0, maximumPathSum(node->left));
    int rightSum = max(0, maximumPathSum(node->right));
    maxPath = max(maxPath, node->data + leftSum + rightSum);
    return max(node->data + leftSum, node->data + rightSum);
}

void solve() {
    struct Node *root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    root->right->left = new Node(-30);
    root->right->right = new Node(-15);

    // struct Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    maximumPathSum(root);
    cout << maxPath << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}