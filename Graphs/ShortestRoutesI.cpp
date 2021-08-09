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

bool sortComparator(pll a, pll b) {
    if (a.first < b.first) return true;
    if (a.first > b.first) return false;
    return a.second < b.second;
}

void dijkstra(auto &graph, auto &visited, auto &dist, int start) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dist[start] = 0;
    pq.push(mp(0, start));
    while (!pq.empty()) {
        ll node = pq.top().second;
        ll minValue = pq.top().first;
        visited[node] = true;
        pq.pop();
        if (dist[node] < minValue) continue;
        for (auto neighbour : graph[node]) {
            if (visited[neighbour.second]) continue;
            ll newDist = dist[node] + neighbour.first;
            if (newDist < dist[neighbour.second]) {
                dist[neighbour.second] = newDist;
                pq.push(mp(newDist, neighbour.second));
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pll>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    vector<ll> dist(n + 1, INT_MAX);
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(mp(c, b));
    }
    dijkstra(graph, visited, dist, 1);
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