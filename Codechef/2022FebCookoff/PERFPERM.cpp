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
    vi arr;
    for (int i = 0; i <= n; i++) arr.pb(i);
    reverse(arr.begin() + k + 1, arr.end());
    if ((n - k) % 2 != 0) {
        int mid = ((k + 1 + n) / 2);
        swap(arr[mid], arr[mid + 1]);
    }
    // if (arr[k + 1] % (k + 1) == 0) {
    //     swap(arr[k + 1], arr[k + 2]);
    // }
    for (int i = 1 + k; i < n; i++) {
        if (arr[i] % i == 0) {
            swap(arr[i], arr[i + 1]);
            i++;
        }
    }

    for (int i = 1; i <= n; i++) cout << arr[i] << " ";
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