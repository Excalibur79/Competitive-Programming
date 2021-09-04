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
    vector<int> nums = {1};
    int n = nums.size();
    int ans = INT_MAX;
    for (int i = 1; i < n; i++) {
        nums[i] += nums[i - 1];
    }
    for (int i = 0; i < n; i++) {
        int left;
        if (i - 1 >= 0)
            left = nums[i - 1];
        else
            left = 0;
        int right = nums[n - 1] - nums[i];
        if (left == right) ans = min(ans, i);
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
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