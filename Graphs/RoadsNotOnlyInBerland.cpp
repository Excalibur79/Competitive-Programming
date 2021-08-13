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
    } else if (Rank[v] < Rank[u]) {
        Parent[v] = u;
    } else {
        Parent[v] = u;
        Rank[u]++;
    }
}
//======================

void solve() {
    int n;
    cin >> n;
    makeSet(n);
    vector<pii> extraEdges;
    vector<pii> constructEdges;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (Find(a) != Find(b)) {
            Union(a, b);
        } else {
            extraEdges.pb(mp(a, b));
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (Find(i) != Find(j)) {
                constructEdges.pb(mp(i, j));
                Union(i, j);
            }
        }
    }
    cout << constructEdges.size() << endl;
    for (int i = 0; i < constructEdges.size(); i++) {
        cout << extraEdges[i].first << " " << extraEdges[i].second << " "
             << constructEdges[i].first << " " << constructEdges[i].second
             << endl;
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