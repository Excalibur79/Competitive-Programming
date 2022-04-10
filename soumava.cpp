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

int recur(string &a, string &b, int n, int m) {
    if (n == 0 || m == 0) return 0;
    if (a[n - 1] == b[m - 1]) return 1 + recur(a, b, n - 1, m - 1);
    return recur(a, b, n - 1, m) + recur(a, b, n, m - 1);
}

void solve() {
    string a, b;
    cin >> a >> b;
    int ans = recur(a, b, a.size(), b.size());
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