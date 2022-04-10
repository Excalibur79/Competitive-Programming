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
    int a, b;
    cin >> a >> b;
    int ans = 14;
    int i = a, j = b;

    // up left diag
    while (i > 0 && j > 0) {
        ans++;
        i--;
        j--;
    }

    // right up diag
    i = a;
    j = b;
    while (i > 0 && j < 9) {
        ans++;
        i--;
        j++;
    }

    // left down diag
    i = a;
    j = b;
    while (i < 9 && j > 0) {
        ans++;
        i++;
        j--;
    }

    // right down diag
    i = a;
    j = b;
    while (i < 9 && j < 9) {
        ans++;
        i++;
        j++;
    }
    cout << ans - 4 << endl;
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