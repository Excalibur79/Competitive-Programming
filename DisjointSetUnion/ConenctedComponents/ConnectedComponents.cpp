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

void solve() {
    int n, m;
    cin >> n >> m;
    makeSet(n);
    // vector<vector<int>> graph(n);
    map<int, vector<int>> graph;
    for (int i = 0; i < n; i++) {
        graph[i] = {};
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    unordered_set<int> totalParents;
    for (auto data : graph) {
        int node = data.first;
        vector<int> neighbours = data.second;
        for (auto neighbour : neighbours) {
            if (Find(node) != Find(neighbour)) {
                Union(node, neighbour);
            }
        }
    }
    // To Find Total Number OF PArents
    for (auto data : graph) {
        int node = data.first;
        totalParents.insert(Find(node));
    }
    cout << totalParents.size() << endl;
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