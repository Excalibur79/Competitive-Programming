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

void generateSubsets(auto &arr, auto &Set, int currSum, int index, int size) {
    Set.pb(currSum);
    for (int i = index; i < size; i++) {
        currSum += arr[i];
        generateSubsets(arr, Set, currSum, i + 1, size);
        currSum -= arr[i];
    }
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    inputarr(arr, n);
    vector<int> setA, setB;
    generateSubsets(arr, setA, 0, 0, n / 2);
    generateSubsets(arr, setB, 0, n / 2, n);
    // printarr(setA, setA.size());
    // cout << endl;
    // printarr(setB, setB.size());
    // cout << endl;
    sort(setB.begin(), setB.end());
    int ans = 0;
    for (auto data : setA) {
        int low =
            lower_bound(setB.begin(), setB.end(), a - data) - setB.begin();
        int high =
            upper_bound(setB.begin(), setB.end(), b - data) - setB.begin();
        ans += (high - low);
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