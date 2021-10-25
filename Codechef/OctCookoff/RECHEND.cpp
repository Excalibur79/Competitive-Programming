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

bool isValid(auto &grid, auto &visited, int i, int j) {
    if (i >= 0 && i < grid.size() && j >= 0 && j < grid.size() &&
        !visited[i][j]) {
        return grid[i][j];
    }
    return false;
}

void bfs(auto &grid, auto &visited) {
    queue<pii> q;
    q.push(mp(0, 0));
    visited[0][0] = true;
    while (!q.empty()) {
        pii cell = q.front();
        visited[cell.first][cell.second] = true;
        q.pop();
        if (isValid(grid, visited, cell.first + 1, cell.second))
            q.push(mp(cell.first + 1, cell.second));
        if (isValid(grid, visited, cell.first, cell.second + 1))
            q.push(mp(cell.first, cell.second + 1));
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<bool>> visited;
    vector<vector<int>> grid;
    set<pii> blocks;
    for (int i = 0; i < n; i++) {
        vi pint;
        vector<bool> pbool;
        for (int j = 0; j < n; j++) {
            pbool.pb(false);
            pint.pb(1);
        }
        visited.pb(pbool);
        grid.pb(pint);
    }
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        grid[x - 1][y - 1] = 0;
    }
    bfs(grid, visited);
    if (visited[n - 1][n - 1])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int32_t main() {
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