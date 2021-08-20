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

void dfs(auto &graph, auto &visited, int node) {
    visited[node] = true;
    cout << node << " ";
    for (auto neighbour : graph[node]) {
        if (!visited[neighbour]) {
            dfs(graph, visited, neighbour);
        }
    }
}

void bfs(auto &graph, auto &visited, auto &order, int node) {
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(node);
    visited[node] = true;
    while (!pq.empty()) {
        int index = pq.top();
        order.pb(index);
        pq.pop();
        for (auto neighbour : graph[index]) {
            if (!visited[neighbour]) {
                pq.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, set<int>> graph;
    while (m--) {
        int u, v;
        cin >> u >> v;
        // if (u == v) continue;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    vector<bool> visited(n + 1);
    vector<int> order;
    bfs(graph, visited, order, graph.begin()->first);
    printarr(order, order.size());
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