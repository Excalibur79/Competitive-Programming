// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
using namespace std;

#define ll long long
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

string decimalToBinary(ll n, ll fix) {
    string bin = "";
    while (n) {
        bin += to_string(n % 2);
        n /= 2;
    }
    reverse(bin.begin(), bin.end());
    // Make of Size fix
    int cur = bin.size();
    string res = string(fix - cur, '0');
    res += bin;
    return res;
}

ll memoize[1001][1001];

ll lcs(string a, string b, int n, int m) {
    if (n == 0 || m == 0) {
        memoize[n][m] = 0;
        return 0;
    }
    if (memoize[n][m] != -1) return memoize[n][m];
    if (a[n - 1] == b[m - 1]) {
        memoize[n][m] = 1 + lcs(a, b, n - 1, m - 1);
        return memoize[n][m];
    }
    memoize[n][m] = max(lcs(a, b, n - 1, m), lcs(a, b, n, m - 1));
    return memoize[n][m];
}

void solve() {
    string n, m;
    cin >> n >> m;
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            memoize[i][j] = -1;
        }
    }
    ll ans = lcs(n, m, n.size(), m.size());
    cout << (n.size() + m.size() - 2 * ans) << endl;
}

int main() {
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