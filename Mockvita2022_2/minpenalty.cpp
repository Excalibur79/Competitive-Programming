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
    vi arr(n);
    inputarr(arr, n);
    int ans = 0;
    while (!arr.empty()) {
        n = arr.size();
        if (arr.size() > 2) {
            ans += arr[n - 2] * max(arr[n - 3], arr[n - 1]) -
                   min(arr[n - 3], arr[n - 1]);
            vector<int>::iterator it = arr.end();
            --(--it);
            arr.erase(it);
        } else if (arr.size() == 1) {
            ans += arr[n - 1];
            arr.pop_back();
        } else if (arr.size() == 2) {
            int indexR;
            int indexK;
            if (arr[n - 2] <= arr[n - 1]) {
                indexR = n - 2;
                indexK = n - 1;
            } else {
                indexR = n - 1;
                indexK = n - 2;
            }
            ans += arr[indexR] * arr[indexK];
            vector<int>::iterator it = arr.begin() + indexR;
            arr.erase(it);
        }
    }
    cout << ans;
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