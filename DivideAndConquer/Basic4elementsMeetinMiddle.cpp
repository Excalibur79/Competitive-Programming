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
    int n, summ;
    cin >> n >> summ;
    vector<int> arr(n);
    inputarr(arr, n);
    map<int, vector<pair<int, int>>> m;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            m[arr[i] + arr[j]].pb(mp(i, j));
        }
    }
    // for (auto data : m)
    //     cout << data.first << " =>"
    //          << "(" << data.second.first << "," << data.second.second << ")"
    //          << endl;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (m.find(summ - (arr[i] + arr[j])) != m.end()) {
                pii pair1 = m[summ - (arr[i] + arr[j])];
                pii pair2 = m[arr[i] + arr[j]];
                if (pair1.first != pair2.first &&
                    pair1.second != pair2.second) {
                    cout << arr[pair1.first] << " " << arr[pair1.second] << " "
                         << arr[pair2.first] << " " << arr[pair2.second]
                         << endl;
                    return;
                }
            }
        }
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