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
vector<vector<int>> dp;
string res = "";

int LCS(string &s, string &t, int n, int m) {
    if (n <= 0 || m <= 0) return 0;
    if (dp[n][m] != -1) return dp[n][m];
    if (s[n - 1] == t[m - 1]) return dp[n][m] = 1 + LCS(s, t, n - 1, m - 1);
    return dp[n][m] = max(LCS(s, t, n - 1, m), LCS(s, t, n, m - 1));
}

void solve() {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i <= s.length(); i++) {
        vector<int> p;
        for (int j = 0; j <= t.length(); j++) {
            p.pb(-1);
        }
        dp.pb(p);
    }
    LCS(s, t, s.length(), t.length());
    int i = s.length(), j = t.length();
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            res += s[i - 1];
            i--;
            j--;
        } else {
            if (dp[i][j - 1] >= dp[i - 1][j])
                j--;
            else
                i--;
        }
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
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