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

vector<bool> visited;
vector<int> tin;
vector<int> low;
int timer = 0;

void dfs(auto &graph, int node, int parent) {
    visited[node] = true;
    tin[node] = low[node] = timer++;
    for (auto neighbour : graph[node]) {
        if (neighbour == parent) continue;

        if (!visited[neighbour]) {
            dfs(graph, neighbour, node);
            low[node] = min(low[node], low[neighbour]);
            if (low[neighbour] > tin[node]) {
                cout << node << " " << neighbour << endl;
            }
        } else {  // remember this is else , so ekhono backtrack hoini so its
                  // now updating its lowest values by checking with neighbours
            low[node] = min(low[node], tin[neighbour]);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    for (int i = 0; i < n; i++) {
        visited.pb(false);
        tin.pb(-1);
        low.pb(-1);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(graph, i, -1);
        }
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