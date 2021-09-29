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
    if (k == n - 1)
        cout << -1;
    else if (k == n) {
        for (int i = 1; i <= n; i++) cout << i << " ";

    } else {
        for (int i = 1; i <= k; i++) {
            cout << i << " ";
        }
        if ((n - k) % 2 == 0) {
            for (int i = n; i > k; i--) cout << i << " ";
        } else {
            vi arr;
            for (int i = n; i > k; i--) arr.pb(i);
            swap(arr[(n - k) / 2], arr[n - k - 1]);
            for (auto value : arr) cout << value << " ";
        }
    }
    cout << endl;
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