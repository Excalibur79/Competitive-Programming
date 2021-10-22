// Author: Bihan Chakraborty
// Linkedin: https://www.linkedin.com/in/bihan-chakraborty
// Github: https://github.com/Bihan001

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
const int MOD = 1e9 + 7;
const int INF = 1e18;
#define inputarr(arr, n) \
    for (int i = 0; i < n; i++) cin >> arr[i];
#define printarr(arr, n) \
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';

vector<vector<string>> dp;

string lcs(int i, int j, string &s, string &t) {
    if (i == s.length() || j == t.length()) return "";
    if (dp[i][j] != "\0") return dp[i][j];
    if (s[i] == t[j]) return dp[i][j] = (s[i] + lcs(i + 1, j + 1, s, t));
    string str1 = lcs(i + 1, j, s, t);
    string str2 = lcs(i, j + 1, s, t);
    if (str1.length() > str2.length())
        return dp[i][j] = str1;
    else
        return dp[i][j] = str2;
}

void solve() {
    string s, t;
    cin >> s >> t;
    dp.resize(s.length(), vector<string>(t.length(), "\0"));
    string ans = lcs(0, 0, s, t);
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