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

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, set<pii>> graph;
    vector<vector<int>> edges;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >>> a >> b;
        graph[a].insert(mp(1, b));
        graph[b].insert(mp(1, a));
        edges.pb({a, b, c});
    }
    for (int i = 0; i <= m; i++) {
        vi edge = edges[i];
        graph[edge[0]].erase(mp(1, edge[1]));
        dijkstra()
    }
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