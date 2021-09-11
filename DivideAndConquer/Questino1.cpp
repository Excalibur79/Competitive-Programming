// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

// Given an array representing n positions along a straight line
// Find k elements from the array such that the minimum distance between any two
// points is maximized

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

bool isPossible(auto &arr, int space, int numberOfDigits) {
    int i = 0;
    numberOfDigits--;
    for (int j = 1; j < arr.size(); j++) {
        if (arr[j] - arr[i] >= space) {
            numberOfDigits--;
            i = j;
        }
        if (numberOfDigits == 0) break;
    }
    return numberOfDigits == 0;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    inputarr(arr, n);
    sort(arr.begin(), arr.end());
    int l = INT_MAX;
    int h = INT_MIN;
    for (int i = 1; i < n; i++) {
        l = min(l, arr[i] - arr[i - 1]);
        h = max(h, arr[i] - arr[i - 1]);
    }
    int res = -1;
    l = 1, h = arr[n - 1];
    cout << l << " ss " << h << endl;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (isPossible(arr, mid, k)) {
            res = mid;
            l = mid + 1;
        } else
            h = mid - 1;
    }
    cout << res << endl;
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