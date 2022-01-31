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
    vector<int> arr, ans;
    for (int i = 0; i < n; i++) arr.pb(i);
    sort(arr.begin(), arr.end());
    int i = 0, j = n - 1;
    while (i <= j) {
        if (i != j) {
            ans.pb(arr[j--]);
            ans.pb(arr[i++]);
        } else
            ans.pb(arr[i++]);
    }
    for (auto data : ans) cout << data << " ";
    cout << endl;
    vi gg;
    i = 0;

    while (i + 1 < 10) {
        gg.pb(ans[i] ^ ans[i + 1]);
        i++;
    }
    cout << "val : " << *max_element(gg.begin(), gg.end());
    cout << endl;
    // for (int data : ans) cout << data << " ";
    // cout << endl;
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