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
    vector<int> arr(n);
    inputarr(arr, n);
    int x = 0;
    for (int data : arr) {
        x = x ^ data;
    }
    // finding first set bit index from right
    int idx = 0;
    int y = x;
    while (y && 1 == 0) {
        idx++;
        y = y >> 1;
    }
    // doing xor of all elements with bit set at index idx
    int z = 0;
    for (int data : arr) {
        if (data & (1 << idx)) z ^= data;
    }
    cout << min(z, x ^ z) << " " << max(z, z ^ x) << endl;
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