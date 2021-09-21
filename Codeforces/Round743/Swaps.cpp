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
    vector<int> a(n), b(n);
    inputarr(a, n);
    inputarr(b, n);
    int ans = INT_MAX;
    map<int, int> checkA;
    for (int i = 0; i < n; i++) {
        checkA[-a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        int value = -b[i];
        auto it = checkA.lower_bound(value);
        while (it != checkA.end()) {
            // cout << value << " " << b[i] << endl;
            int index = it->second;
            ans = min(ans, index + i);
            value = it->first + 1;
            checkA.erase(it);
            it = checkA.lower_bound(value);
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