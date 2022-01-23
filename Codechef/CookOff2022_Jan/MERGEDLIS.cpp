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

bool comp(vi &a, vi &b) {
    if (a[2] == b[2])  // same type
        return a[1] <= b[1];
    else
        return a[0] <= b[0];
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a;
    vector<vector<int>> b;
    vector<vector<int>> c;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.pb({x, i, 0});
        c.pb({x, i, 0});
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.pb({x, i, 1});
        c.pb({x, i, 1});
    }
    sort(c.begin(), c.end(), comp);
    for (auto data : c) cout << data[0] << " ";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}