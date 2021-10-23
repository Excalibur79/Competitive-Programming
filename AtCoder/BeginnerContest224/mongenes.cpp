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
    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid;
    for (int i = 1; i <= r; i++) {
        vi p;
        for (int j = 1; j <= c; j++) {
            int x;
            cin >> x;
            p.pb(x);
        }
        grid.pb(p);
    }

    for (int r2 = 1; r2 < r; r2++) {
        for (int r1 = 0; r1 < r2; r1++) {
            for (int c2 = 1; c2 < c; c2++) {
                for (int c1 = 0; c1 < c2; c1++) {
                    if (grid[r1][c1] + grid[r2][c2] >
                        grid[r2][c1] + grid[r1][c2]) {
                        cout << "No" << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "Yes" << endl;
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