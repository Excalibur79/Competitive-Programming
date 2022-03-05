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
    vi arr(n);
    inputarr(arr, n);
    int k = 1;
    int i = 0, j = -1;
    if (arr[j] == 0) k--;
    int ans = INT_MIN;
    while (j < n) {
        j++;
        if (j >= n) break;
        if (arr[j] == 0) {
            if (k == 0) {
                while (k == 0) {
                    if (arr[i] == 0) k++;
                    i++;
                }
                k = 0;
            } else
                k--;
        }
        // cout << i << " " << j << " " << k << endl;
        ans = max(ans, j - i + 1);
    }
    cout << ans - 1 << endl;
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