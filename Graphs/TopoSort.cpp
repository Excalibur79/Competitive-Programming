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

bool sortComparator(pll a, pll b) {
    if (a.first < b.first) return true;
    if (a.first > b.first) return false;
    return a.second < b.second;
}

stack<int> ans;

void dfs(int node, vector<int> &visited, vector<int> &adj[]) {
    visited[node] = true;
    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) dfs(neighbour, visited, adj);
    }
    ans.push(node);
}

vector<int> solve(int V, vector<int> adj[]) {
    vector<bool> visited(V);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) dfs(i, visited, adj);
    }
    vector<int> res;
    while (!ans.empty) {
        res.pb(ans.top());
        ans.pop();
    }
    return res;
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