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

void zeroOneBfs(auto &graph, auto &dist, int start) {
    list<pii> l;
    dist[start] = 0;
    l.push_back(mp(0, start));
    while (!l.empty()) {
        int node = l.front().second;
        int minValue = l.front().first;
        l.pop_front();
        for (auto neighbour : graph[node]) {
            int neighbourIndex = neighbour.second;
            int wt = neighbour.first;
            int newDist = wt + dist[node];
            if (newDist < dist[neighbourIndex]) {
                dist[neighbourIndex] = newDist;
                if (wt == 0) {
                    l.push_front(mp(newDist, neighbourIndex));
                } else {
                    l.push_back(mp(newDist, neighbourIndex));
                }
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, vector<pii>> graph;
    vector<ll> dist(n, INT_MAX);
    for (int i = 0; i < n; i++) {
        graph[i] = {};
    }
    // assuming graph has single components
    // neighbour node { weight , index }
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].pb(mp(c, b));
        graph[b].pb(mp(c, a));
    }

    zeroOneBfs(graph, dist, 1);
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