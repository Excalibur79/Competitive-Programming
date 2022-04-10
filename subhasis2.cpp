
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
    map<int, int> hash;
    for (int i = 0; i < n; i++) hash[arr[i]] = i;
    auto it = hash.begin();
    int i = 0;
    while (it != hash.end()) {
        // cout << it->first << " " << arr[i] << endl;
        if (it->first != arr[i]) {
            if ((it->first + arr[i]) % 2 != 0) {
                cout << "NO" << endl;
                return;
            }
        }
        ++it;
        i++;
    }
    cout << "YES" << endl;
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