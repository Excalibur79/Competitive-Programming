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
    string s;
    cin >> n >> s;
    int ans = 0;
    set<int> indexes;
    int zeroes = 0;
    for (char c : s)
        if (c == '0') zeroes++;
    if (zeroes == n) {
        cout << 0 << endl;
        return;
    }

    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1] && s[i] == '1') {
            cout << 2 << endl;
            return;
        }
    }
    cout << 1 << endl;
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