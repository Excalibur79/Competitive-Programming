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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int li = i - k;
        int ri = i + k;
        if (s[i] == '1') {
            if (li >= 0) {
                if (s[li] == '1') continue;
            }
            if (ri < n) {
                if (s[ri] == '1') continue;
            }
            if (li < 0 && ri >= n) {
                s[i] = '0';
                ans++;
            } else if (ri < n) {
                s[ri] = '1';
                ans++;
            } else {
                s[li] = '1';
                ans++;
            }
        }
    }
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