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

vector<ll> memoize;

ll dp(ll n, ll m) {
    if (n == 1) return 1;
    if (n < 1) return 0;
    if (memoize[n] != -1) return memoize[n];
    // try subtraction
    ll ways = 0;
    for (ll i = 1; i < n; i++) {
        ll returnValue = dp(n - i, m);
        if (n - i >= 1) ways = (ways % m + returnValue % m) % m;
    }
    // try division
    for (ll i = 2; i <= n; i++) {
        ll returnValue = dp(n / i, m);
        if (n / i >= 1) ways = (ways % m + returnValue % m) % m;
    }
    return memoize[n] = ways % m;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i <= n + 1; i++) {
        memoize.pb(-1);
    }
    ll ans = dp(n, m);
    cout << ans;
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