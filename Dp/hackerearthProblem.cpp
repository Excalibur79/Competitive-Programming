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

int dp(auto &x, auto &toys, int curPos, int curSteps, int n) {
    if (n == 0 || curSteps == 0) return 0;
    int stepsNeeded = abs(curPos - x[n - 1]);
    if (stepsNeeded <= curSteps) {
        return max(
            toys[n - 1] + dp(x, toys, x[n - 1], curSteps - stepsNeeded, n - 1),
            dp(x, toys, curPos, curSteps, n - 1));
    }
    return dp(x, toys, curPos, curSteps, n - 1);
}

void solve() {
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> x(n);
    vector<int> toys(n);
    inputarr(x, n);
    inputarr(toys, n);
    int ans = dp(x, toys, p, k, n);
    cout << ans << endl;
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