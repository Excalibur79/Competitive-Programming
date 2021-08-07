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

class Edge {
   public:
    int u, v, wt;
    Edge(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

void solve() {
    bool negetiveCyclePresent = false;
    int vertices, e;
    cin >> vertices >> e;
    vector<Edge> edges;
    while (e--) {
        int u, v, wt;
        cin >> u >> v >> wt;
        Edge newEdge(u, v, wt);
        edges.push_back(newEdge);
    }
    vector<ll> dist(vertices, INT_MAX);
    int start;
    cin >> start;
    dist[start] = 0;
    for (int i = 1; i <= vertices - 1; i++) {
        for (auto &edge : edges) {
            if (dist[edge.u] + edge.wt < dist[edge.v])
                dist[edge.v] = dist[edge.u] + edge.wt;
        }
    }
    // one more round to check if there present a negetive cycle
    for (auto edge : edges) {
        if (dist[edge.u] + edge.wt < dist[edge.v]) {
            negetiveCyclePresent = true;
            break;
        }
    }
    //=========================================================
    if (negetiveCyclePresent)
        cout << "Negetive Cycle Present !" << endl;
    else
        printarr(dist, dist.size());
    // for (auto edge : edges) {
    //     cout << edge.u << " " << edge.v << " " << edge.wt << endl;
    // }
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