// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
using namespace std;

#define ll long long
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

// Disjoint Set Functions
vector<ll> Parent;

void makeSet(int n) {
    for (ll i = 0; i < n + 2; i++) {
        Parent.pb(i);
    }
}

ll Find(ll u) {
    if (Parent[u] == u)
        return u;
    else
        Parent[u] = Find(Parent[u]);
}

void Union(ll left, ll right) {
    left = Find(left);
    right = Find(right);
    Parent[left] = right;
}
//======================

void solve() {
    ll n, q;
    cin >> n >> q;
    makeSet(n);
    vector<vector<ll>> queries;
    for (int i = 0; i < q; i++) {
        ll l, r, c;
        cin >> l >> r >> c;
        vector<ll> query = {l, r, c};
        queries.pb(query);
    }
    // reverse(queries.begin(), queries.end());
    vector<ll> res(n + 2);
    for (ll i = q - 1; i >= 0; i--) {
        auto data = queries[i];
        ll left = Find(data[0]);
        ll right = data[1];
        ll color = data[2];
        ll index = left;
        while (index <= right) {
            res[index] = color;
            Union(index, index + 1);
            index = Find(index);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << endl;
    }
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