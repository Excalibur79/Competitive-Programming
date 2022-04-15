// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79
#include <bits/stdc++.h>

#include <climits>
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

int m, n;

bool isValid(vector<vector<int>> &grid, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n) return false;
    if (grid[i][j] == -1) return false;
    return true;
}

int recur(vector<vector<int>> &dp, vector<vector<int>> &grid, int i, int j) {
    // cout << i << " " << j << endl;
    if (dp[i][j] != -1) return dp[i][j];
    if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
        return dp[i][j] = grid[i][j];
    }
    int data = INF;
    vector<int> rowConfig = {-1, -1, -1, 1, 1, 1, 0, 0};
    vector<int> colConfig = {-1, 0, 1, -1, 0, 1, -1, 1};
    for (int x = 0; x < 8; x++) {
        if (isValid(grid, i + rowConfig[x], j + colConfig[x])) {
            int val = grid[i][j];
            grid[i][j] = -1;
            data = min(data, val + recur(dp, grid, i + rowConfig[x],
                                         j + colConfig[x]));
            grid[i][j] = val;
        }
    }
    return dp[i][j] = data;
}

void solve() {
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int a = 0, b = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 0) {
                a = i;
                b = j;
            }
            grid[i][j] = x;
        }
    }

    // cout << endl;
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int ans = recur(dp, grid, a, b);
    // cout << endl;
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans;
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