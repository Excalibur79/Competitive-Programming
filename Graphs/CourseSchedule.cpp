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

int find(int u) {
    if (Parent[u] == u)
        return u;
    else {
        return Parent[u] = find(Parent[u]);
    }
}

void Union(int u, int v) {
    u = find(u);
    v = find(v);
    if (Rank[u] < Rank[v]) {
        Parent[u] = v;

    } else if (Rank[v] < Rank[u]) {
        Parent[v] = u;
    } else {
        Parent[v] = u;
        Rank[u]++;
    }
}

bool checkCycle(auto &graph) {
    makeSet(graph.size());
    for (auto value : graph) {
        int node = value.first;
        vector<int> neighbours = value.second;
        for (auto neighbour : neighbours) {
            if (find(node) != find(neighbour)) {
                Union(node, neighbour);
            } else
                return true;
        }
    }
    return false;
}
//======================

// Toposort Functions
stack<int> ans;
vector<bool> visited;

void dfs(auto &graph, int node) {
    visited[node] = true;
    for (auto neighbour : graph[node]) {
        if (!visited[neighbour]) dfs(graph, neighbour);
    }
    ans.push(node);
}

void topoSort(auto &graph) {
    for (int i = 0; i <= graph.size(); i++) visited.pb(false);
    for (auto value : graph) {
        int node = value.first;
        if (!visited[node]) {
            dfs(graph, node);
        }
    }
}
//==================

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> graph;
    for (int i = 1; i <= n; i++) {
        graph[i] = {};
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
    }
    bool isCyclePresent = checkCycle(graph);
    if (isCyclePresent) {
        for (int i = 0; i < Parent.size(); i++) {
            cout << i << " ";
        }
        cout << endl;
        for (auto value : Parent) {
            cout << value << " ";
        }
        cout << endl << "IMPOSSIBLE" << endl;
    } else {
        topoSort(graph);
        while (!ans.empty()) {
            cout << ans.top() << " ";
            ans.pop();
        }
        // cout << ans.size() << endl;
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