// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long int
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

bool isLeaf(struct TreeNode *node) { return !node->left && !node->right; }

void addLeftBoundary(struct TreeNode *node, vector<int> &res) {
    while (!isLeaf(node)) {
        res.pb(node->val);
        if (node->left)
            node = node->left;
        else if (node->right)
            node = node->right;
    }
}

void addRightBoundary(struct TreeNode *node, vector<int> &res) {
    stack<int> s;
    while (!isLeaf(node)) {
        s.push(node->val);
        if (node->right)
            node = node->right;
        else if (node->left)
            node = node->left;
    }
    while (!s.empty()) {
        res.pb(s.top());
        s.pop();
    }
}

void addLeafNodes(struct TreeNode *node, vector<int> &res) {
    if (isLeaf(node)) {
        res.pb(node->val);
        return;
    }
    if (node->left) addLeafNodes(node->left, res);
    if (node->right) addLeafNodes(node->right, res);
}

void solve() {
    struct TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->left->right->right->left = new TreeNode(7);
    root->left->right->right->left->left = new TreeNode(8);
    root->left->right->right->left->left->left = new TreeNode(9);
    root->left->right->right->left->left->right = new TreeNode(10);

    vector<int> res;
    if (root) {
        if (!isLeaf(root)) res.pb(root->val);
        addLeftBoundary(root->left, res);
        addLeafNodes(root, res);
        addRightBoundary(root->right, res);
        for (auto data : res) cout << data << " ";
    }
}

int32_t main() {
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