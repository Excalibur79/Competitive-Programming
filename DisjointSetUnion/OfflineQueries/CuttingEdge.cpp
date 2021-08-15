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

// Disjoint set Functions
vector<int> Parent;
vector<int> Rank;

void makeSet(int n) {
    for (int i = 0; i <= n; i++) {
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
    } else if (Rank[v] < Rank[u])
        Parent[v] = u;
    else {
        Parent[u] = v;
        Rank[v]++;
    }
}
//=====================

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    makeSet(n);
    vector<pair<string, pair<int, int>>> queries;
    while (m--) {
        int a, b;
        cin >> a >> b;
    }
    while (k--) {
        string type;
        int x, y;
        cin >> type >> x >> y;
        queries.pb(mp(type, mp(x, y)));
    }
    reverse(queries.begin(), queries.end());
    vector<string> ans;
    for (auto data : queries) {
        string type = data.first;
        int a = data.second.first;
        int b = data.second.second;
        if (type == "GET") {
            if (Find(a) == Find(b))
                ans.pb("YES");
            else
                ans.pb("NO");
        } else if (type == "CUT") {
            if (Find(a) != Find(b)) Union(a, b);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto data : ans) {
        cout << data << endl;
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