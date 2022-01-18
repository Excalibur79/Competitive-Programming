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
    vector<int> arr(n);
    inputarr(arr, n);
    int maxx, secondMaxx;
    maxx = max(arr[0], arr[1]);
    secondMaxx = min(arr[0], arr[1]);
    for (int i = 2; i < n; i++) {
        if (arr[i] > maxx) {
            secondMaxx = maxx;
            maxx = arr[i];

        } else if (arr[i] > secondMaxx && arr[i] < maxx)
            secondMaxx = arr[i];

        // cout << secondMaxx << " " << maxx << endl;
    }
    cout << secondMaxx << endl;
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