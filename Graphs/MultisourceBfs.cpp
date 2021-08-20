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
    for (ll i = 1; i < n; i++) cout << arr[i] << ' ';

void multiSourceBfs(auto &graph, auto &sources, auto &visited, auto &dist) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (auto source : sources) {
        //  visited[source] = true;
        pq.push(mp(0, source));
        dist[source] = 0;
    }
    while (!pq.empty()) {
        ll node = pq.top().second;
        ll minValue = pq.top().first;
        if (dist[node] < minValue) continue;
        visited[node] = true;
        pq.pop();
        for (auto neighbour : graph[node]) {
            if (visited[neighbour]) continue;
            ll newDist = dist[node] + 1;
            if (newDist < dist[neighbour]) {
                dist[neighbour] = newDist;
                pq.push(mp(newDist, neighbour));
            }
        }
    }
}

void solve() {
    int n = 6, m = 9;
    int sources[] = {1, 5};
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vector<ll> dist(n + 1, INF);
    vector<bool> visited(n + 1);
    multiSourceBfs(graph, sources, visited, dist);
    printarr(dist, dist.size());
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