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

bool pathExist = false;

stack<int> bfs(vector<vector<int>> &graph, vector<bool> &visited,
               vector<int> &prev, int start, int end) {
    visited[start] = true;
    prev[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto neighbour : graph[node]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                prev[neighbour] = node;
                q.push(neighbour);
                if (neighbour == end) {
                    pathExist = true;
                    break;
                }
            }
        }
        if (pathExist) break;
    }
    stack<int> path;
    int node = end;
    path.push(node);
    while (prev[node] != 0) {
        node = prev[node];
        path.push(node);
    }
    return path;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1);
    vector<int> prev(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // for (auto v : graph) {
    //     for (auto x : v) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    stack<int> ans = bfs(graph, visited, prev, 1, n);
    if (!pathExist) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << ans.size() << endl;
        while (!ans.empty()) {
            cout << ans.top() << " ";
            ans.pop();
        }
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