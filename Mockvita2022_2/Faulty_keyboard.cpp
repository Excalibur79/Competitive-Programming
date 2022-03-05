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
    string t, s;
    getline(cin, t);
    getline(cin, s);
    unordered_map<char, int> steps;
    steps[s[0]] = s.length() - 1;
    for (int i = 1; i < s.length(); i++) {
        steps[s[i]] = s.length() - 1 + 2;
    }
    int ans = 0;
    for (auto data : steps) cout << data.first << " " << data.second << endl;
    for (char c : t) {
        if (steps.find(c) != steps.end()) {
            ans += steps[c];
        }
    }
    cout << ans;
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