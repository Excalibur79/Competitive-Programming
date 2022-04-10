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

void recur(vector<vector<int>> &grid, int i, int j, int n, int m,
           vector<pair<int, int>> &path, int minVal) {
    if (grid[i][j] <= 0) return;

    if (i == n - 1 && j == n - 1) {
        path.pb({i, j});
        for (pair<int, int> data : path)
            grid[data.first][data.second] -= minVal;
        path = {};
        recur(grid, 0, 0, n, m, path, grid[0][0]);
    }

    if (grid[i][j] < minVal) minVal = grid[i][j];
    path.pb(mp(i, j));

    if (i + 1 < n && grid[i + 1][j] > 0) {
        return recur(grid, i + 1, j, n, m, path, minVal);
    }
    if (j + 1 < m && grid[i][j + 1] > 0) {
        return recur(grid, i, j + 1, n, m, path, minVal);
    }
    return;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<pair<int, int>> path;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> grid[i][j];
    }

    recur(grid, 0, 0, n, m, path, grid[0][0]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != 0) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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