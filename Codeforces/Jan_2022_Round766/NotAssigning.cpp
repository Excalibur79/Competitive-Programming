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

bool possible = true;

int dfs(auto &graph, auto &visited, auto &colors, int node, int edgeColor) {
    if (graph[node].size() > 2)
        possible = false;
    else {
        visited[node] = true;
        for (auto neighbour : graph[node]) {
            if (!visited[neighbour]) {
                colors[mp(node, neighbour)] = edgeColor;
                colors[mp(neighbour, node)] = edgeColor;
                dfs(graph, visited, colors, neighbour, edgeColor == 2 ? 3 : 2);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    unordered_map<int, vector<int>> graph;
    vector<bool> visited(n);
    map<pii, int> colors;
    vector<pii> edges;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].pb(v);
        graph[v].pb(u);
        edges.pb(mp(u, v));
    }
    dfs(graph, visited, colors, 0, 2);
    if (possible) {
        for (auto data : edges) {
            cout << colors[mp(data.first, data.second)] << " ";
        }
        cout << endl;
    } else
        cout << -1 << endl;
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