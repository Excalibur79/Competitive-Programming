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
    n *= 2;
    vi arr(n);
    vi sortedArr;
    inputarr(arr, n);
    map<int, int> m;
    for (int data : arr) m[data]++;
    for (auto data : m) sortedArr.pb(data.first);
    // prefix check
    for (int i = 0; i < sortedArr.size(); i++) m[sortedArr[i / 2]]--;

    // suffix check
    for (int i = sortedArr.size() - 1; i >= 0; i--)
        m[sortedArr[(sortedArr.size() - 1 + i) / 2]]--;

    for (auto data : m) {
        if (data.second != 0) {
            cout << -1 << endl;
            return;
        }
    }
    printarr(sortedArr, sortedArr.size());
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