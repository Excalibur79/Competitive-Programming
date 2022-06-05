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
const ll eps = 1e-6;
#define inputarr(arr, n) \
    for (ll i = 0; i < n; i++) cin >> arr[i];
#define printarr(arr, n) \
    for (ll i = 0; i < n; i++) cout << arr[i] << ' ';

void solve() {
    int n, x;
    cin >> n >> x;
    if (x == 1) {
        cout << "YES" << endl;
        return;
    }
    if (n % 2 != 0 && x % 2 != 0) {
        if ((n - x) % 2 != 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return;
    }
    if (n % 2 != 0 && x % 2 == 0) {
        cout << "NO" << endl;
        return;
    }
    if (n % 2 == 0 && x % 2 == 0) {
        cout << "YES" << endl;
        return;
    }
    if (n % 2 == 0 && x % 2 != 0) {
        if ((n - x) % 2 != 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return;
    }
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