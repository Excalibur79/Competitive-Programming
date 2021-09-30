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
    set<pii> s, copyS;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x > 0) {
            s.insert(mp(x, i));
            copyS.insert(mp(x, i));
        }
    }
    auto first = s.begin(), last = --s.end();
    int counter = 0;
    // for (auto value : s) cout << value.first << " ";
    // cout << endl;
    vector<pii> ans;
    while (s.size() > 1) {
        first = s.begin();
        last = --s.end();
        int low = first->first;
        int high = last->first;
        ans.pb(mp(first->second, last->second));
        low--;
        high--;
        counter++;
        if (low > 0) s.insert(mp(low, first->second));
        if (high > 0) s.insert(mp(high, last->second));
        s.erase(first);
        s.erase(last);
        // for (auto value : s) cout << value.first << " ";
        // cout << endl;
    }
    cout << counter << endl;
    for (auto value : ans) {
        cout << value.first << " " << value.second << endl;
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