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

int subsetSum(vector<vector<int>> &dp, auto &arr, int n, int sum) {
    if (sum == 0) return dp[n][sum] = 1;
    if (n == 0) return dp[n][sum] = 0;
    if (dp[n][sum] != -1) return dp[n][sum];
    if (arr[n - 1] <= sum)
        return dp[n][sum] = subsetSum(dp, arr, n - 1, sum - arr[n - 1]) +
                            subsetSum(dp, arr, n - 1, sum);
    return dp[n][sum] = subsetSum(dp, arr, n - 1, sum);
}

void solve() {
    int n, diff;
    cin >> n >> diff;
    vector<int> arr(n);
    inputarr(arr, n);

    int sum = 0;
    for (int value : arr) sum += value;
    vector<vector<int>> dp(n + 1, vector<int>(((sum + diff) / 2) + 1, -1));
    int ans = subsetSum(dp, arr, n, (sum + diff) / 2);
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