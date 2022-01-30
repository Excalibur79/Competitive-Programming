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

int LIS(vector<int> &arr) {
    int n = arr.size();
    if (n == 0) return 0;
    multiset<int> s;
    for (int data : arr) {
        int largestVal = INT_MIN;
        if (!s.empty()) largestVal = *(--s.end());
        if (data >= largestVal)  // non decreasing hole >= hoye jabe
            s.insert(data);
        else {
            auto removeIt = s.upper_bound(data);
            s.erase(removeIt);
            s.insert(data);
        }
    }
    // for (int data : s) cout << data << " ";

    return s.size();
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    // vector<int> c;
    inputarr(a, n);
    inputarr(b, m);
    // int i = 0, j = 0;
    // while (i < n && j < m) {
    //     if (a[i] < b[j]) {
    //         c.pb(a[i]);
    //         i++;
    //     } else {
    //         c.pb(b[j]);
    //         j++;
    //     }
    // }
    // while (i < n) {
    //     c.pb(a[i]);
    //     i++;
    // }
    // while (j < m) {
    //     c.pb(b[j]);
    //     j++;
    // }
    // for (int data : c) cout << data << " ";
    // cout << endl;
    // LIS(c);
    // cout << endl;
    cout << LIS(a) + LIS(b) << endl;
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