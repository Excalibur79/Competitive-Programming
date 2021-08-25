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
        ll powerNeeded = cave.first;
        ll bonusHealthAfterCave = cave.second;
        if (health >= powerNeeded)
            health += bonusHealthAfterCave;
        else
            return false;
    }
    return true;
}

void solve() {
    ll n;
    cin >> n;
    vector<pll> caves;

    ll l = INT_MAX, h = INT_MIN;
    for (int i = 1; i <= n; i++) {
        ll k;
        cin >> k;
        ll neededPowerForThisCave = -1;
        for (int i = 0; i < k; i++) {
            ll x;
            cin >> x;
            neededPowerForThisCave = max(neededPowerForThisCave, x - i + 1);
        }
        l = min(l, neededPowerForThisCave);
        h = max(h, neededPowerForThisCave);
        caves.pb(mp(neededPowerForThisCave, k));
    }
    sort(caves.begin(), caves.end());
    // l = 0, h = INT_MAX;
    ll res = -1;
    while (l <= h) {
        mid = (l + h) / 2;
        if (isPossible(caves, mid)) {
            res = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << endl;
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