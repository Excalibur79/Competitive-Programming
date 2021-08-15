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

bool checkBipartite(auto &graph, auto &colors, int start) {
    queue<int> q;
    colors[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto neighbour : graph[node]) {
            if (colors[neighbour] == -1) {
                colors[neighbour] = colors[node] == 0 ? 1 : 0;
                q.push(neighbour);
            } else {
                if (colors[neighbour] == colors[node]) return false;
            }
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> colors(n + 1, -1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    bool isBipartite = checkBipartite(graph, colors, 1);
    if (isBipartite)
        cout << (n * 2) % 998244353 << endl;
    else
        cout << 0 << endl;
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