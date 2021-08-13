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

int zeroOneBfs(auto &graph, auto &dist, int start) {
    list<pii> l;
    l.push_back(mp(0, start));
    dist[start] = 0;
    while (!l.empty()) {
        int node = l.front().second;
        int minValue = l.front().first;
        l.pop_front();
        for (auto neighbour : graph[node]) {
            int index = neighbour.second;
            int wt = neighbour.first;
            int newDist = dist[node] + wt;
            if (newDist < dist[index]) {
                dist[index] = newDist;
                if (wt == 0)
                    l.push_front(mp(newDist, index));
                else
                    l.push_back(mp(newDist, index));
            }
        }
    }
    return dist[graph.size()];
}

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, vector<pii>> graph;
    vector<ll> dist(n + 1, INT_MAX);
    for (int i = 1; i <= n; i++) {
        graph[i] = {};
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(mp(0, b));
        graph[b].pb(mp(1, a));
    }
    int ans = zeroOneBfs(graph, dist, 1);
    cout << (ans != INT_MAX ? ans : -1) << endl;
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