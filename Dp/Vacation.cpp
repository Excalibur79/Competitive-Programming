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

int vacation(auto &dp, auto &days, int n, int exclude) {
    if (n == 0) return dp[n][exclude] = 0;
    if (dp[n][exclude] != -1) return dp[n][exclude];
    vector<int> indexes = {0, 1, 2};
    auto it = find(indexes.begin(), indexes.end(), exclude);
    indexes.erase(it);
    // cout << "exclude :" << exclude << " indexes: " << indexes[0] << ", "
    //      << indexes[1] << endl;
    return dp[n][exclude] = max((days[n - 1][indexes[0]] +
                                 vacation(dp, days, n - 1, indexes[0])),
                                (days[n - 1][indexes[1]] +
                                 vacation(dp, days, n - 1, indexes[1])));
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> days;
    vector<vector<int>> dp(n + 1, {-1, -1, -1});
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        days.pb({a, b, c});
    }
    int ans = max(days[n - 1][0] + vacation(dp, days, n - 1, 0),
                  max(days[n - 1][1] + vacation(dp, days, n - 1, 1),
                      days[n - 1][2] + vacation(dp, days, n - 1, 2)));
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