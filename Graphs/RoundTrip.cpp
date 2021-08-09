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

bool possible = false;
int cycleStart, cycleEnd;

void dfs(auto &graph, auto &visited, auto &prev, int node) {
    visited[node] = true;
    for (auto neighbour : graph[node]) {
        if (!visited[neighbour]) {
            prev[neighbour] = node;
            dfs(graph, visited, prev, neighbour);
        } else {
            if (prev[node] != neighbour) {
                cycleStart = node;
                cycleEnd = neighbour;
                possible = true;
                break;
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> prev(n + 1, 0);
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i < graph.size(); i++) {
        if (!visited[i]) {
            dfs(graph, visited, prev, i);
        }
        if (possible) break;
    }
    cout << endl;
    if (possible) {
        vector<int> ans;
        ans.push_back(cycleStart);
        int size = 0;
        int node = cycleEnd;
        while (node != cycleStart) {
            ans.push_back(node);
            node = prev[node];
        }
        ans.push_back(cycleStart);
        cout << ans.size() << endl;
        printarr(ans, ans.size());
        // for (int i = 1; i < prev.size(); i++) {
        //     cout << i << " " << prev[i] << endl;
        // }
    } else {
        cout << "IMPOSSIBLE" << endl;
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