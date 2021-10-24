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
    vector<int> arr;
    vector<int> toSort1;
    vector<int> toSort2;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i % 2 == 0)
            toSort1.pb(x);
        else
            toSort2.pb(x);
        arr.pb(x);
    }
    sort(toSort1.begin(), toSort1.end(), greater<int>());
    sort(toSort2.begin(), toSort2.end());
    int k = 0;
    for (int i = 0; i < n; i = i + 2) {
        arr[i] = toSort1[k++];
    }
    k = 0;
    for (int i = 1; i < n; i = i + 2) {
        arr[i] = toSort2[k++];
    }
    printarr(arr, n);
    cout << endl;
    int ans = 0;
    for (int i = 0; i < n; i = i + 2) {
        for (int j = i + 1; j < n; j = j + 2) {
            ans += arr[i] * arr[j];
        }
    }
    cout << ans << endl;
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