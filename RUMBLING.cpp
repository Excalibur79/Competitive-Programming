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

void solve() {
    int n;
    cin >> n;
    vector<char> titans(n);
    inputarr(titans, n);
    vector<int> east(n);
    vector<int> west(n);
    int c, a;
    cin >> c >> a;
    for (int i = 0; i < n; i++) {
        char value = titans[i];
        if (value == 'S') {
            west[i] = min(c, 3 * a);
            east[i] = min(a, 3 * c);
        }
        if (value == 'N') {
            west[i] = min(a, 3 * c);
            east[i] = min(c, 3 * a);
        }
        if (value == 'E') {
            east[i] = 0;
            west[i] = min(2 * c, 2 * a);
        }
        if (value == 'W') {
            west[i] = 0;
            east[i] = min(2 * c, 2 * a);
        }
    }
    // prefix sum
    for (int i = 1; i < n; i++) {
        west[i] += west[i - 1];
        east[i] += east[i - 1];
    }
    int ans = min(west[n - 1], east[n - 1]);
    for (int i = 0; i < n; i++) {
        int wl = west[i];
        int el = east[i];
        int wr = west[n - 1] - west[i];
        int er = east[n - 1] - east[i];
        ans = min(ans, el + wr);
    }
    cout << ans << endl;
    // printarr(west, n);
    // cout << endl;
    // printarr(east, n);
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