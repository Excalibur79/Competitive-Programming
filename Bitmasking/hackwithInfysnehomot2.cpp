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
    vector<int> arr1(n);
    vector<int> arr2(n);
    multiset<int> arr2Set;
    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr2[i] = x;
        arr2Set.insert(x);
    }
    // for (int data : arr2Set) cout << data << " ";
    // cout << endl;
    vector<int> c;
    for (int i = 0; i < n; i++) {
        int data = arr1[i];
        auto val1It = arr2Set.lower_bound(data);
        auto val2It = val1It;
        --val2It;
        // cout << *val2It << " " << *val1It << i << endl;
        if (val1It == arr2Set.end()) {
            c.push_back(*val2It);
            arr2Set.erase(val2It);
            continue;
        }
        if (val2It == arr2Set.end()) {
            c.push_back(*val1It);
            arr2Set.erase(val1It);
            continue;
        }
        if (abs(*val1It - data) < abs(*val2It - data)) {
            c.push_back(*val1It);
            arr2Set.erase(val1It);
        } else {
            c.push_back(*val2It);
            arr2Set.erase(val2It);
        }
    }
    int val = -1;
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (val == -1) {
            val = arr1[i] ^ c[i];
        } else {
            if (val != arr1[i] ^ c[i]) {
                break;
                possible = false;
            }
        }
    }
    if (!possible) {
        cout << -1 << endl;
    } else {
        printarr(c, n);
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