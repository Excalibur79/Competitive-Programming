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

void buildSegTree(auto &arr, auto &segTree, int l, int r, int index) {
    if (l == r) {
        segTree[index] = arr[l];
    } else {
        int mid = (l + r) / 2;
        buildSegTree(arr, segTree, l, mid, 2 * index);
        buildSegTree(arr, segTree, mid + 1, r, 2 * index + 1);
        segTree[index] = min(segTree[2 * index], segTree[2 * index + 1]);
    }
}

void update(auto &segTree, int ss, int se, int i, int increment, int index) {
    if (i < ss || i > se) {
        return;
    }
    // leaf node that means we found the node that needs to be updated
    if (ss == se) {
        segTree[index] += increment;
        return;
    } else {  // the i is within ss and se
        int mid = (ss + se) / 2;
        update(segTree, ss, mid, i, increment, 2 * index);
        update(segTree, mid + 1, se, i, increment, 2 * index + 1);
        segTree[index] = min(segTree[2 * index], segTree[2 * index + 1]);
    }
}

int query(auto &segTree, int ss, int se, int qs, int qe, int index) {
    // complete overlap
    if (ss >= qs && se <= qe) {
        return segTree[index];
    }
    if (qs > se || qe < ss)  // No Overlap
        return INT_MAX;
    else {  // partial overlap
        int mid = (ss + se) / 2;
        int leftAns = query(segTree, ss, mid, qs, qe, 2 * index);
        int rightAns = query(segTree, mid + 1, se, qs, qe, 2 * index + 1);
        return min(leftAns, rightAns);
    }
}

void solve() {
    vector<int> arr = {1, 3, 2, -5, 6, 4};
    int n = arr.size();
    vector<int> segTree(4 * n + 1, -99);
    buildSegTree(arr, segTree, 0, n - 1, 1);
    // printarr(segTree, 4 * n + 1);
    int q;
    cin >> q;
    update(segTree, 0, n - 1, 3, 10, 1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(segTree, 0, n - 1, l, r, 1) << endl;
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