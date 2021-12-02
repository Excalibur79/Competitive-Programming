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

int minNumberOfCoins(vector<vector<long long>> dp, vector<int> &coins, int n,
                     int sum) {
    if (sum == 0) return dp[n][sum] = 0;
    if (n == 0) return dp[n][sum] = INT_MAX;
    if (n == 1) {
        if (sum % coins[n - 1] == 0) return dp[n][sum] = sum / coins[n - 1];
        return dp[n][sum] = INT_MAX;
    }
    if (dp[n][sum] != -1) return dp[n][sum];

    if (coins[n - 1] <= sum)
        return dp[n][sum] =
                   min(1 + minNumberOfCoins(dp, coins, n, sum - coins[n - 1]),
                       minNumberOfCoins(dp, coins, n - 1, sum));
    return dp[n][sum] = minNumberOfCoins(dp, coins, n - 1, sum);
}

void solve() {
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);
    inputarr(coins, n);
    vector<vector<long long>> dp(n + 1, vector<long long>(sum + 1, -1));
    int ans = minNumberOfCoins(dp, coins, n, sum);
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