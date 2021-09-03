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
    vector<ll> a(n);
    vector<ll> b(n - 1);
    inputarr(a, n);
    inputarr(b, n - 1);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = abs(b[0] - a[1]);
    int firstElementLeft = true;
    for (int i = 0; i < n - 1; i++) {
        int x = b[i] - ans;
        if (x != a[i + 1]) {
            ans = b[0] - a[0];
        }
    }
    cout << (ans > 0 ? ans : b[0] - a[0]) << endl;
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