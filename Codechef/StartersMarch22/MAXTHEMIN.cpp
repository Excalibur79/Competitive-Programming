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
    vi arr(n);
    inputarr(arr, n);

    map<int, vector<int>> freq;
    for (int i = 0; i < arr.size(); i++) {
        freq[arr[i]].pb(i);
    }
    if (freq.size() == 1) {
        cout << arr[0] << endl;
        return;
    }
    int minVal = freq.begin()->first;
    while (k && !freq.empty()) {
        int val = freq.begin()->first;
        vi indexes = freq.begin()->second;
        if (indexes.size() > k) break;
        for (int id : indexes) {
            arr[id] = max(id - 1 >= 0 ? arr[id - 1] : INT_MIN,
                          id + 1 < n ? arr[id + 1] : INT_MIN);
        }
        freq.erase(freq.begin());
        if (!freq.empty()) minVal = freq.begin()->first;
        k = k - indexes.size();
    }
    cout << minVal << endl;
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