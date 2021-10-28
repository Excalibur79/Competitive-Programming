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

vector<int> lazy(100000);  // actually make it a size of 4*n+1;

void updateRangeLazy(auto &segTree, int ss, int se, int l, int r, int increment,
                     int index) {
    // before going down rewsolve the value if it exits
    if (lazy[index] != 0) {
        segTree[index] += lazy[index];
        if (ss != se) {  // non leaf node then pass the lazy value to just its
                         // immediate children
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] = lazy[index];
        }
        lazy[index] = 0;  // clear the lazy value at current node
    }

    // case of no overlap
    if (l > se || r < ss) return;

    // another case - complete overlap
    if (ss >= l && r <= se) {
        segTree[index] += increment;
        // create a new lazy value for children node
        if (ss != se) {
            lazy[2 * index] += increment;
            lazy[2 * index + 1] += increment;
        }
    }
    // case of partial overlap
    else {
        int mid = (ss + se) / 2;
        updateRangeLazy(segTree, ss, mid, l, r, increment, 2 * index);
        updateRangeLazy(segTree, mid + 1, se, l, r, increment, 2 * index + 1);
        segTree[index] = min(segTree[2 * index], segTree[2 * index + 1]);
        return;
    }
}

void buildSegTree(auto &arr, auto &segTree, int ss, int se, int index) {
    if (ss == se) {
        segTree[index] = arr[se];
    } else {
        int mid = (Ss + se) / 2;
        buildSegTree(arr, segTree, ss, mid, 2 * index);
        buildSegTree(arr, segTree, mid + 1, se, 2 * index + 1);
        segTree[index] = min(segTree[2 * index], segTree[2 * index + 1]);
    }
}

void solve() {
    vector<int> arr = {1, 3, 2, -5, 6, 4};
    int n = arr.size();
    vector<int> segTree(4 * n + 1, -99);
    buildSegTree(arr, segTree, 0, n - 1, 1);
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