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
    vi arr(n);
    inputarr(arr, n);
    set<int> left;
    set<int> right;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            left.insert(-i);
            right.insert(i);
        }
    }
    if (!left.empty()) {
        for (int i = 0; i < n; i++) {
            int leftVal = left.upper_bound(-i) != left.end()
                              ? left.upper_bound(-i)
                              : left.upper_bound(n - 1);
            leftVal = leftVal * -1;
            int rightVal = right.upper_bound(i) != right.end()
                               ? right.upper_bound(i)
                               : right.upper_bound(0);
            int leftDistance, rightDistance;
            if (leftVal < i)
                leftDistance = i - leftVal;
            else
                leftDistance = n - leftVal + 1;
            if (rightVal > i)
                rightDistance = rightVal - i;
            else
                rightDistance = rightVal + 1;

            int leftDistance = abs(-1 * (*left.lower_bound(leftSearchIndex)) -
                                   (-leftDistance)) +
                               1;
            int rightDistance =
                abs(*right.lower_bound(rightSearchIndex) - rightDistance) + 1;

            arr[i] += ((k - leftDistance) * 1);
            arr[i] += ((k - rightDistance) * 1);
        }
    }

    int summ = 0;
    for (auto value : arr) summ += value;
    cout << summ << endl;
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