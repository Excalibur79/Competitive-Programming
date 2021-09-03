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
    int n, k;
    cin >> n >> k;
    vector<pii> arr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.pb(mp(x, i));
    }
    sort(arr.begin(), arr.end(), greater<pii>());
    vector<pii> ans;
    int median;
    for (int i = 0; i < k; i++) {
        ans.pb(mp(arr[i].second, arr[i].first));
    }
    median = ans[(k / 2)].second;
    sort(ans.begin(), ans.end());
    cout << median << endl;
    for (auto value : ans) cout << value.second << " ";
    cout << endl;
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