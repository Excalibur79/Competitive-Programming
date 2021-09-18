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

vector<vector<int>> res;

void generateSubsets(auto &arr, auto &subset, int index, int n) {
    res.pb(subset);
    for (int i = index; i < n; i++) {
        subset.pb(arr[i]);
        generateSubsets(arr, subset, i + 1, n);
        subset.pop_back();
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> subset;
    inputarr(arr, n);
    generateSubsets(arr, subset, 0, n);
    for (auto data : res) {
        for (auto value : data) cout << value << " ";
        cout << endl;
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