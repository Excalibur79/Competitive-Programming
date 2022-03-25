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
    int n, x;
    cin >> n;
    vector<int> arr(n);
    multiset<int> arrSet;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        arr[i] = l;
        arrSet.insert(l);
    }
    cin >> x;
    int ans = 0;
    while (!arrSet.empty()) {
        int data = *arrSet.begin();
        if (arrSet.find(data ^ x) != arrSet.end()) {
            auto it1 = arrSet.find(data);
            auto it2 = arrSet.find(data ^ x);
            arrSet.erase(it1);
            arrSet.erase(it2);
        } else {
            ans++;
            auto it1 = arrSet.find(data);
            arrSet.erase(it1);
        }
    }
    cout << ans << endl;
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