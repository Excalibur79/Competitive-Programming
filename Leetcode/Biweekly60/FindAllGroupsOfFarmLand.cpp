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

vector<vector<int>> ans;

bool isValid(auto &land, auto &visited, int i, int j) {
    if (i < 0 || j >= land[0].size() || i >= land.size() || j < 0) return false;
    if (visited[i][j]) return false;
    if (land[i][j] == 0) return false;
    return true;
}

void bfs(auto &land, auto &visited, int i, int j) {
    queue<pii> q;
    set<pii> cells;
    cells.insert(mp(i, j));
    visited[i][j] = true;
    q.push(mp(i, j));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        vector<int> xConfig = {-1, 1, 0, 0};
        vector<int> yConfig = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int newX = x + xConfig[i];
            int newY = y + yConfig[i];
            if (isValid(land, visited, newX, newY)) {
                visited[newX][newY] = true;
                cells.insert(mp(newX, newY));
                q.push(mp(newX, newY));
            }
        }
    }
    vector<int> blockAns;
    pii start = *cells.begin();
    pii end = *(--cells.end());
    blockAns.pb(start.first);
    blockAns.pb(start.second);
    blockAns.pb(end.first);
    blockAns.pb(end.second);
    ans.pb(blockAns);
}

void solve() {
    vector<vector<int>> land = {{1, 0, 0}, {0, 1, 1}, {0, 1, 1}};
    int m = land.size();
    int n = land[0].size();
    vector<vector<bool>> visited;
    for (int i = 0; i < m; i++) {
        vector<bool> p;
        for (int j = 0; j < n; j++) {
            p.pb(false);
        }
        visited.pb(p);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && land[i][j]) {
                bfs(land, visited, i, j);
            }
        }
    }

    for (auto data : ans) {
        for (auto value : data) cout << value << " ";
        cout << endl;
    }
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