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

void buildSegTree(auto &arr, auto &segTree, int ss, int se, int index) {
    if (ss == se) {
        segTree[index] = arr[se];
    } else {
        int mid = (ss + se) / 2;
        buildSegTree(arr, segTree, ss, mid, 2 * index);
        buildSegTree(arr, segTree, mid + 1, se, 2 * index + 1);
        segTree[index] = min(segTree[2 * index], segTree[2 * index + 1]);
    }
}

int query(auto &segTree, int ss, int se, int qs, int qe, int index) {
    if (ss >= qs && se <= qe)  // complete overlap
        return segTree[index];
    if (qs > se || qe < ss)
        return INT_MAX;
    else {
        int mid = (ss + se) / 2;
        int left = query(segTree, ss, mid, qs, qe, 2 * index);
        int right = query(segTree, mid + 1, se, qs, qe, 2 * index + 1);
        return min(left, right);
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    vector<int> segTree(4 * n + 1);
    inputarr(arr, n);
    buildSegTree(arr, segTree, 0, n - 1, 1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = query(segTree, 0, n - 1, l - 1, r - 1, 1);
        cout << ans << endl;
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