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
    vector<char> poles(n);
    inputarr(poles, n);
    int numberOfNs = 0;
    for (char pole : poles) {
        if (pole == 'N') numberOfNs++;
    }
    if (is_sorted(arr.begin(), arr.end()))
        cout << 0 << endl;
    else if (numberOfNs == 0 | numberOfNs == n)
        cout << -1 << endl;
    else {
        if (poles[0] != poles[n - 1])
            cout << 1 << endl;
        else
            cout << 2 << endl;
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