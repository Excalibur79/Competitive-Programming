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

// Directed Graph Cycle Detection Functions
vector<bool> Visited;
vector<bool> dfsVisited;

bool checkCycle(auto &graph, int node) {
    Visited[node] = true;
    dfsVisited[node] = true;
    for (auto neighbour : graph[node]) {
        if (!Visited[neighbour]) {
            if (checkCycle(graph, neighbour)) return true;
        }

        else {
            if (dfsVisited[neighbour]) return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

bool isCyclic(auto &graph) {
    for (int i = 0; i <= graph.size(); i++) {
        Visited.pb(false);
        dfsVisited.pb(false);
    }

    for (auto value : graph) {
        int node = value.first;
        if (!Visited[node]) {
            if (checkCycle(graph, node)) return true;
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
    bool isCyclePresent = isCyclic(graph);
    if (isCyclePresent) {
        cout << "IMPOSSIBLE" << endl;
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