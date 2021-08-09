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

printGraph(auto graph) {
    for (auto value : graph) {
        cout << value.first << " =>";
        for (auto data : value.second) cout << data << " ";
        cout << endl;
    }
}

void initiateGenocide(map<int, unordered_set<int>> &graph) {
    int ans = 0;
    while (graph.size() > 0) {
        int king = graph.begin()->first;
        while (graph.size() > 0) {
            // cout << king << "asd" << endl;
            if (graph[king].size() == 0) {
                ans++;
                graph.erase(king);
                king++;
            } else {
                // cout << "broken" << endl;
                break;
            }
        }

        int weakestKing = graph.begin()->first;
        for (auto &neighbour : graph[weakestKing]) {
            graph[neighbour].erase(weakestKing);
        }
        graph.erase(weakestKing);
        // printGraph(graph);
    }

    cout << ans << endl;
}

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, unordered_set<int>> graph;
    map<int, unordered_set<int>> copyGraph;
    for (int i = 1; i <= n; i++) {
        unordered_set<int> newSet;
        graph[i] = newSet;
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    copyGraph = graph;

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        switch (type) {
            case 1:
                int x, y;
                cin >> x >> y;
                copyGraph[x].insert(y);
                copyGraph[y].insert(x);
                break;
            case 2:
                cin >> x >> y;
                copyGraph[x].erase(y);
                copyGraph[y].erase(x);
                break;
            case 3:
                initiateGenocide(copyGraph);
                copyGraph = graph;
                break;
            default:
                break;
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