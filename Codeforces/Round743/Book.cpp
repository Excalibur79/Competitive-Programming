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

int ans = 0;

bool cyclePresent(auto &graph, auto &visited, auto &dfsVisited, int node) {
    visited[node] = true;
    dfsVisited[node] = true;
    for (auto neighbour : graph[node]) {
        if (!visited[neighbour]) {
            if (cyclePresent(graph, visited, dfsVisited, neighbour))
                return true;
        } else if (dfsVisited[neighbour])
            return true;
    }
    dfsVisited[node] = false;
    return false;
}

bool isCyclic(auto &graph, auto &visited, auto &dfsVisited) {
    for (auto data : graph) {
        int node = data.first;
        if (!visited[node]) {
            ans++;
            if (cyclePresent(graph, visited, dfsVisited, node)) return true;
        }
    }
    return false;
}

void solve() {
    ans = 0;
    int n;
    cin >> n;
    map<int, vi> graph;
    vector<bool> visited(n + 1, false), dfsVisited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            graph[x].pb(i);
        }
    }
    if (isCyclic(graph, visited, dfsVisited))
        cout << -1 << endl;
    else {
        cout << ans << endl;
    }
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