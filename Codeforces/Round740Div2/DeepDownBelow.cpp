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

ll mid;

bool isPossible(auto &caves, ll health) {
    for (auto cave : caves) {
        for (auto monsterHealth : cave) {
            if (health > monsterHealth) {
                health++;
            } else
                return false;
        }
    }
    return true;
}

bool comparator(auto cave1, auto cave2) {
    if (cave1[0] > mid && cave2[0] > mid) return cave1.size() <= cave2.size();
    return cave1[0] >= mid;
}

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> caves;
    ll sum = 0;
    ll l = INT_MAX, h = INT_MIN;
    for (int i = 1; i <= n; i++) {
        ll k;
        cin >> k;
        vector<ll> p;
        while (k--) {
            ll x;
            cin >> x;
            sum += x;
            h = max(h, x + 1);
            l = min(l, x + 1);
            p.pb(x);
        }
        caves.pb(p);
    }

    // l = 0, h = INT_MAX;
    ll res = -1;
    while (l <= h) {
        mid = (l + h) / 2;
        sort(caves.begin(), caves.end(), comparator);
        if (isPossible(caves, mid)) {
            res = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << endl;

    cout << endl;
    for (auto cave : caves) {
        for (auto monsterHealth : cave) {
            cout << monsterHealth << " ";
        }
        cout << endl;
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