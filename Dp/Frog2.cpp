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

int frogJump(auto &dp, auto &heights, int n, int k) {
    if (n == 1) return dp[n] = 0;
    if (n == 2) return dp[n] = abs(heights[n - 1] - heights[n - 2]);
    if (dp[n] != -1) return dp[n];
    int temp = INT_MAX;
    // abs(heights[n - 1] - heights[n - 2]) + frogJump(heights, n - 1, k);
    for (int i = 1; i <= min(n - 1, k); i++) {
        temp = min(temp, (abs(heights[n - 1] - heights[n - 1 - i]) +
                          frogJump(dp, heights, n - i, k)));
    }
    return dp[n] = temp;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> heights(n);
    vector<int> dp(n + 1, -1);
    inputarr(heights, n);
    int ans = frogJump(dp, heights, n, k);
    cout << ans << endl;
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