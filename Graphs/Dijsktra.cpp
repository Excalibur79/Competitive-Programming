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

void dijkstra(auto &graph, auto &dist, auto &visited, int start) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push(mp(dist[start], start));
    while (!pq.empty()) {
        int node = pq.top().second;
        int minValue = pq.top().first;
        pq.pop();
        visited[node] == true;
        if (dist[node] < minValue) continue;
        for (int i = 0; i < graph[node].size(); i++) {
            if (graph[node][i]) {
                if (visited[i]) continue;
                int newDist = dist[node] + graph[node][i];
                if (newDist < dist[i]) {
                    dist[i] = newDist;
                    pq.push(mp(newDist, i));
                }
            }
        }
    }
}

void solve() {
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},  {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},  {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0}, {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},  {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    vector<int> dist(graph.size(), INT_MAX);
    vector<bool> visited(graph.size());
    dijkstra(graph, dist, visited, 0);
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