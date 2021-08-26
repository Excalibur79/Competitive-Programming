// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
using namespace std;

#define ll long long
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
    ll k;
    string n;
    cin >> k >> n;
    ll length = n.size();
    bool ansOne = false;
    char ans;
    bool breakNow = false;
    for (char c : n) {
        if (c != '2' && c != '3' && c != '5' && c != '7') {
            ansOne = true;
            ans = c;
            break;
        }
    }
    if (ansOne) {
        cout << 1 << endl;
        cout << ans << endl;
    } else {
        // sort(n.begin(), n.end());
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                string s;
                s.pb(n[i]);
                s.pb(n[j]);
                if (s == "25" || s == "35" || s == "27" || s == "22" ||
                    s == "55" || s == "77" || s == "33" || s == "52" ||
                    s == "72" || s == "75") {
                    cout << 2 << endl;
                    cout << s << endl;
                    breakNow = true;
                    break;
                }
            }
            if (breakNow) break;
        }
    }
}

int main() {
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