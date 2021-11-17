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

vector<int> numberOfZeroes;

int perfectSum(vector<int> &arr, int summ, int n) {
    if (summ == 0 && n != 0) return pow(2, numberOfZeroes[n - 1]);
    if (summ == 0 && n == 0) return 1;
    if (n == 0) return 0;
    if (arr[n - 1] <= summ)
        return perfectSum(arr, summ - arr[n - 1], n - 1) +
               perfectSum(arr, summ, n - 1);
    return perfectSum(arr, summ, n - 1);
}

void solve() {
    int n, summ;
    cin >> n >> summ;
    vector<int> arr(n);
    inputarr(arr, n);
    numberOfZeroes.resize(n, 0);
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) ++counter;
        numberOfZeroes[i] = counter;
    }
    // printarr(numberOfZeroes, n);
    // cout << endl;
    int ans = perfectSum(arr, summ, n);
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