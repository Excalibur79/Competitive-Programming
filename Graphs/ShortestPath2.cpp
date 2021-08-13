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

void floydWarshall(auto &graph) {
    ll n = graph.size();
    for (int k = 1; k < n; k++) {
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> graph;
    for (int i = 0; i <= n; i++) {
        vector<ll> p;
        for (int j = 0; j <= n; j++) {
            p.pb(INF);
        }
        graph.pb(p);
        graph[i][i] = 0;
    }
    while (m--) {
        int a, b;
        ll c;
        cin >> a >> b;
        cin >> c;
        graph[a][b] = min(graph[a][b], c);
        graph[b][a] = min(graph[a][b], c);
    }
    floydWarshall(graph);
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (graph[a][b] == INF)
            cout << -1 << endl;
        else
            cout << graph[a][b] << endl;
    }
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