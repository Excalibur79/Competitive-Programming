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

void flip(string &s, int i, int j) {
    for (int k = i; k <= j; k++) {
        s[k] = s[k] == '0' ? '1' : '0';
    }
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<pii> order;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') continue;
        for (int j = 0; j <= i; j++) s[j] = s[j] == '0' ? '1' : '0';
        // for(int x=0;x<=j;x++){
        //     if(s[x]=='0')
        //         f
        // }
        order.pb(mp(1, i + 1));
        // cout << s << endl;
    }

    cout << order.size() << endl;
    for (auto data : order) cout << data.first << " " << data.second << endl;
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