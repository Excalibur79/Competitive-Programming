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

vector<int> dp(1000001, -1);

int recur(vector<int> &lasers, vector<int> &prefix, int n) {
    if (n <= 0) return 0;
    if (dp[n] != -1) return dp[n];
    if (lasers[n] == -1) return dp[n] = recur(lasers, prefix, n - 1);
    int id1 = max(0, n - lasers[n]);
    int id2 = n;
    int thisDestroys = prefix[id2] - (id1 - 1 >= 0 ? prefix[id1 - 1] : 0) - 1;
    return dp[n] = min(1 + recur(lasers, prefix, n - 1),
                       thisDestroys + recur(lasers, prefix, max(0, id1 - 1)));
}

void solve() {
    int n;
    cin >> n;
    vector<int> lasers(1000001, -1);
    int maxX = INT_MIN;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        lasers[x] = y;
        maxX = max(maxX, x);
    }
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    vector<int> prefix(1000001, 0);
    for (int i = 0; i <= 1000000; i++) {
        if (lasers[i] > 0) prefix[i] = 1;
    }
    for (int i = 1; i <= 1000000; i++) prefix[i] += prefix[i - 1];
    // for (int i = 0; i <= 3; i++) cout << prefix[i] << " ";
    // cout << endl;
    int ans = recur(lasers, prefix, maxX);
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