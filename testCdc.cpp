// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
using namespace std;
#include <unistd.h>
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
    string s;
    cin >> s;
    vi zeroes = {};
    vi ones = {};
    vector<vector<int>> ans = {};
    if (s[0] == '0')
        zeroes.pb(0);
    else
        ones.pb(1);
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            if (s[i] == '0')
                zeroes.pb(0);
            else
                ones.pb(1);
        } else {
            if (s[i - 1] == '0') {
                ans.pb(zeroes);
                zeroes = {};
            } else {
                ans.pb(ones);
                ones = {};
            }
            if (s[i] == '0')
                zeroes.pb(0);
            else
                ones.pb(1);
        }
    }
    if (ones.size() > 1) ans.pb(ones);
    if (zeroes.size() > 1) ans.pb(zeroes);
    for (auto data : ans) {
        for (auto value : data) {
            cout << value << " ";
        }
        cout << endl;
    }
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