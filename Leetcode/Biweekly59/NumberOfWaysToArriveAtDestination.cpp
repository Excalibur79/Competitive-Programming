// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define vll vector<ll>
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define inputarr(arr, n) \
    for (ll i = 0; i < n; i++) cin >> arr[i];
#define prllarr(arr, n) \
    for (ll i = 0; i < n; i++) cout << arr[i] << ' ';

void dijkstra(vector<vector<pair<ll, ll>>> &graph, vector<ll> &dist,
              vector<bool> &visited, vector<ll> &ways, ll start) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dist[start] = 0;
    ways[start] = 1;
    pq.push(mp(dist[start], start));
    while (!pq.empty()) {
        ll node = pq.top().second;
        ll minValue = pq.top().first;
        pq.pop();
        visited[node] = true;
        if (dist[node] < minValue) continue;
        for (auto neighbour : graph[node]) {
            ll index = neighbour.second;
            ll wt = neighbour.first;
            if (visited[index]) continue;
            ll newDist = dist[node] + wt;
            if (newDist == dist[index])
                ways[index] = (ways[index] + ways[node]) % MOD;
            else if (newDist < dist[index]) {
                dist[index] = newDist;
                pq.push(mp(newDist, index));
                ways[index] = ways[node] % MOD;
            }
        }
    }
}

void solve() {
    ll n = 7;
    vector<vector<ll>> roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3},
                                {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1},
                                {0, 4, 5}, {4, 6, 2}};
    // vector<vector<ll>> roads = {{1, 0, 10}};
    vector<vector<pair<ll, ll>>> graph(n);
    for (auto edge : roads) {
        ll a = edge[0];
        ll b = edge[1];
        ll wt = edge[2];
        graph[a].pb(mp(wt, b));
        graph[b].pb(mp(wt, a));
    }
    vector<bool> visited(n);
    vector<ll> dist(n, INF);
    vector<ll> ways(n, 0);
    dijkstra(graph, dist, visited, ways, 0);
    cout << ways[n - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}