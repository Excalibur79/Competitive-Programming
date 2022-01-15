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

void solve() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    r--;
    c--;
    vector<vector<char>> grid;
    bool hasBlack = false;
    for (int i = 0; i < n; i++) {
        vector<char> p = {};
        for (int j = 0; j < m; j++) {
            char x;
            cin >> x;
            if (x == 'B') hasBlack = true;
            p.pb(x);
        }
        grid.pb(p);
    }
    if (grid[r][c] == 'B')
        cout << 0 << endl;
    else {
        // checking row
        for (int i = 0; i < m; i++) {
            if (grid[r][i] == 'B') {
                cout << 1 << endl;
                return;
            }
        }
        // checking cols
        for (int i = 0; i < n; i++) {
            if (grid[i][c] == 'B') {
                cout << 1 << endl;
                return;
            }
        }
        if (hasBlack)
            cout << 2 << endl;
        else
            cout << -1 << endl;
    }
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