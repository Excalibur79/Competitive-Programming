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

// Disjoint Set Functions
vector<int> Parent;
vector<int> Rank;

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        Parent.pb(i);
        Rank.pb(0);
    }
}

int Find(int u) {
    if (Parent[u] == u)
        return u;
    else
        return Parent[u] = Find(Parent[u]);
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (Rank[u] < Rank[v]) {
        Parent[u] = v;

    } else if (Rank[v] < Rank[u]) {
        Parent[v] = u;
    } else {
        Parent[u] = v;
        Rank[v]++;
    }
}
//======================

bool comp(vector<int> &a, vector<int> &b) { return a[2] < b[2]; }

void solve() {
    int n, m;
    cin >> n >> m;
    makeSet(n + 10);
    vector<vector<int>> edges;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.pb({a, b, c});
    }
    int ans = 0;
    sort(edges.begin(), edges.end(), comp);
    for (auto edge : edges) {
        int a = edge[0];
        int b = edge[1];
        int wt = edge[2];
        if (Find(a) != Find(b))
            Union(a, b);
        else if (wt > 0)
            ans += wt;
    }
    cout << ans << endl;
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