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

int recur(int n) {
    if (n == 0) return 0;
    if (n <= 6) return 15;
    if (n <= 8) return 20;
    if (n <= 10) return 25;
    int val1 = (n / 6) * 15 + recur(n % 6);
    int val2 = (n / 8) * 20 + recur(n % 8);
    int val3 = (n / 10) * 25 + recur(n % 10);
    // int val1 = 1, val2 = 2, val3 = 3;
    return min(val1, min(val2, val3));
}

void solve() {
    int n;
    cin >> n;
    int ans = recur(n);
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