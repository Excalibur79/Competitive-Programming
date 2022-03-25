// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
using namespace std;

#define ll long long
// #define int long long int
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

int coins = 0;

vector<char> split_str(string s) {
    vector<char> ans;
    for (int i = 0; i < (int)s.size(); i++) {
        ans.pb(s[i]);
    }
    return ans;
}

bool isPossible(vector<vector<char>> &graph, vector<vector<bool>> &visited,
                int i, int j) {
    if (i < 0 || i >= (int)graph.size() || j < 0 || j >= (int)graph.size())
        return false;
    if (visited[i][j] || graph[i][j] == 'N') return false;
    return true;
}

void dfs(vector<vector<char>> &graph, vector<vector<bool>> &visited, int i,
         int j) {
    visited[i][j] = true;
    coins++;
    vector<int> rowConfig = {-1, 0, 1, 0};
    vector<int> colConfig = {0, -1, 0, 1};
    for (int x = 0; x < 4; x++) {
        if (isPossible(graph, visited, i + rowConfig[x], j + colConfig[x])) {
            dfs(graph, visited, i + rowConfig[x], j + colConfig[x]);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> graph;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<char> p = split_str(s);
        graph.pb(p);
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) cout << graph[i][j] << " ";
    //     cout << endl;
    // }

    vector<int> vals;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 'C' && !visited[i][j]) {
                coins = 0;
                dfs(graph, visited, i, j);
                vals.pb(coins);
            }
        }
    }
    int p1 = 0, p2 = 0;
    sort(vals.begin(), vals.end(), greater<int>());
    for (int i = 0; i < vals.size(); i++) {
        if (i % 2 == 0) {
            p1 += vals[i];
        } else
            p2 += vals[i];
    }
    cout << p1 << " " << p2;
}

int32_t main() {
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