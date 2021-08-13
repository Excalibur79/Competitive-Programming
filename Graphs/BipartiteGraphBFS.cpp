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

void printGraph(auto &graph) {
    for (auto data : graph) {
        int node = data.first;
        vector<int> neighbours = data.second;
        cout << node << " => ";
        for (auto neighbour : neighbours) {
            cout << neighbour << " ";
        }
        cout << endl;
    }
}

int invertColor(int color) { return color == 0 ? 1 : 0; }

bool checkBipartite(auto &graph, auto &colors, int start) {
    queue<int> q;
    colors[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto neighbour : graph[node]) {
            if (colors[neighbour] == -1) {
                colors[neighbour] = invertColor(colors[node]);
                q.push(neighbour);
            } else if (colors[neighbour] == colors[node])
                return false;
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> graph;
    vector<int> colors(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        graph[i] = {};
    }
    // assuming graph has single components
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    bool isBipartite = checkBipartite(graph, colors, 1);
    cout << (isBipartite ? "YES" : "NO") << endl;
    printGraph(graph);
    printarr(colors, colors.size());
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