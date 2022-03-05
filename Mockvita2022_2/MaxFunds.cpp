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

int val = 0;

void dfs(map<int, vector<int>> &graph, map<int, bool> &visited,
         vector<int> &funds, int node) {
    visited[node] = true;
    val += funds[node];
    for (auto neighbour : graph[node]) {
        if (!visited[neighbour]) dfs(graph, visited, funds, neighbour);
    }
}

void solve() {
    val = 0;
    int n;
    cin >> n;
    vector<int> funds(n + 1);
    map<int, vector<int>> graph;
    map<int, bool> visited;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        funds[i] = x;
        visited[i] = false;
    }

    int p;
    cin >> p;
    while (p--) {
        int x, y;
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    int maxAns = INT_MIN;
    for (int i = 1; i <= n; i++) {
        val = 0;
        if (!visited[i]) {
            dfs(graph, visited, funds, i);
            maxAns = max(val, maxAns);
        }
    }
    cout << maxAns;
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