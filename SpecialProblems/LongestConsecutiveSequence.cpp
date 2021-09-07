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
    vector<int> nums(n);
    inputarr(nums, n);
    unordered_set<int> numSet;
    for (auto value : nums) numSet.insert(value);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int length = 0;
        if (numSet.find(nums[i] - 1) == numSet.end()) {
            int number = nums[i];
            // cout << number << " ";
            while (true) {
                if (numSet.find(number) != numSet.end()) {
                    length++;
                    number++;
                } else
                    break;
            }
            // cout << endl;
        }

        ans = max(ans, length);
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