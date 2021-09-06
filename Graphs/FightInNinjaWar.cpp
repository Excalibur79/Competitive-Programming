// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long int
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

map<int, int> colors = {{0, 0}, {1, 0}};

int invertColor(int color) {
    if (color) return 0;
    return 1;
}

void bfs(auto &graph, auto &visited, int node, int color) {
    visited[node] = true;
    queue<pii> q;
    q.push(mp(node, color));
    colors[color]++;
    // cout << "Node :" << node << " color: " << color << endl;
    while (!q.empty()) {
        int index = q.front().first;
        int indexColor = q.front().second;
        q.pop();
        for (auto neighbour : graph[index]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(mp(neighbour, invertColor(indexColor)));
                colors[invertColor(indexColor)]++;
                // cout << "Node :" << neighbour
                //      << " color: " << invertColor(indexColor) << endl;
            }
        }
    }
}

void solve(int testCase) {
    int n;
    cin >> n;
    map<int, vector<int>> graph;
    map<int, bool> visited;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
        visited[a] = false;
        visited[b] = false;
    }
    int ans = 0;
    for (auto data : visited) {
        int node = data.first;
        if (!visited[node]) {
            colors = {{0, 0}, {1, 0}};
            bfs(graph, visited, node, 0);
            ans += max(colors[0], colors[1]);
        }
    }

    cout << "Case " << testCase << ": " << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int i = 0;
    for (int i = 1; i <= t; i++) {
        solve(i);
        if (i != t) cout << endl;
    }
    return 0;
}