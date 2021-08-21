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

void dijkstra(auto graph, auto &dist, auto &slots) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (auto candidate : slots) {
        ll index = candidate.second;
        ll cost = candidate.first;
        dist[index] = cost;
        pq.push(mp(cost, index));
    }
    while (!pq.empty()) {
        ll node = pq.top().second;
        ll minValue = pq.top().first;
        pq.pop();
        for (auto neighbour : graph[node]) {
            ll index = neighbour.second;
            ll wt = neighbour.first;
            ll newDist = wt + dist[node];
            if (newDist < dist[index]) {
                dist[index] = newDist;
                pq.push(mp(newDist, index));
            }
        }
    }
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<ll, ll>>> graph(n + 1);
    // for (int i = 1; i <= n; i++) {
    //     graph[i] = {};
    // }

    vector<ll> dist(n + 1, INT_MAX);
    vector<pll> slots = {};
    while (k--) {
        // extra node = n+1;
        ll x, C;
        cin >> x >> C;
        slots.pb(mp(C, x));
    }
    while (m--) {
        ll a, b, d;
        cin >> a >> b >> d;
        graph[a].pb(mp(d, b));
        graph[b].pb(mp(d, a));
    }
    dijkstra(graph, dist, slots);
    for (int i = 1; i <= n; i++) cout << dist[i] << " ";
    cout << endl;
    dist = {};
}

int main() {
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