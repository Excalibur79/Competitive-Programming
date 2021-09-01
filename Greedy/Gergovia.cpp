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

void solve(int n) {
    vector<int> arr(n);
    inputarr(arr, n);
    vector<pii> buyers;
    vector<pii> sellers;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
            buyers.pb(mp(arr[i], i));
        else
            sellers.pb(mp(arr[i], i));
    }
    int i = 0;
    int j = 0, ans = 0;
    while (i < buyers.size() && j < sellers.size()) {
        int x = min(buyers[i].first, -1 * sellers[j].first);
        buyers[i].first -= x;
        sellers[j].first += x;
        int diff = abs(buyers[i].second - sellers[j].second);
        ans += x * diff;
        if (buyers[i].first == 0) i++;
        if (sellers[j].first == 0) j++;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    do {
        cin >> t;
        if (t != 0) solve(t);
    } while (t != 0);
    return 0;
}