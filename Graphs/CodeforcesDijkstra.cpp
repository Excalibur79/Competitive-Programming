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

bool pathExists = false;
stack<int> path;

void generatePath(auto &prev, int e) {
    path.push(e);
    int node = e;
    while (prev[node] != 0) {
        node = prev[node];
        path.push(node);
    }
}

void dijkstra(auto &graph, auto &visited, auto &dist, auto &prev, int start) {
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
                prev[neighbour.second] = node;
            }
        }
        if (node == dist.size() - 1) {
            pathExists = true;
            generatePath(prev, dist.size() - 1);
            return;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pll>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    vector<ll> prev(n + 1, 0);
    vector<ll> dist(n + 1, INT_MAX);
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(mp(c, b));
        graph[b].push_back(mp(c, a));
    }
    dijkstra(graph, visited, dist, prev, 1);
    if (pathExists) {
        while (!path.empty()) {
            cout << path.top() << " ";
            path.pop();
        }
    } else
        cout << -1 << endl;
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