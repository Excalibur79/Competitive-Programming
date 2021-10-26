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

void update(auto &segTree, int ss, int se, int l, int r, int increment,
            int index) {
    if (l > se || r < ss) return;
    if (ss >= l && se <= r) {
        segTree[index] += increment;
        return;
    } else {
        int mid = (ss + se) / 2;
        update(segTree, ss, mid, l, r, increment, 2 * index);
        update(segTree, mid + 1, se, l, r, increment, 2 * index + 1);
        segTree[index] = segTree[2 * index] + segTree[2 * index + 1];
    }
}

int query(auto &segTree, int ss, int se, int i, int index) {
    if (ss == se) return segTree[index];
}

void solve() {
    int n, q;
    cin >> n >> q;
    vi arr(n);
    inputarr(arr, n);
    vi segTree(4 * n + 1, 0);
    while (q--) {
        int type;
        cin >> type;
        switch (type) {
            case 1:
                int l, r, increment;
                cin >> l >> r >> increment;
                upate(segTree, 0, n - 1, l, r, increment, index);
                break;
            case 2:
                break;
        }
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