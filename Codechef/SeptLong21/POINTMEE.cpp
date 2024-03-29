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

int numberOfOperations(pii point, pii testPoint) {
    if (point == testPoint) return 0;

    vi values = {point.first - testPoint.first, point.second - testPoint.second,
                 testPoint.second - point.second};
    for (int k : values) {
        // checking k1
        if (testPoint.first + k == point.first &&
            testPoint.second == point.second)
            return 1;
        if (testPoint.first == point.first &&
            testPoint.second + k == point.second)
            return 1;
        if (testPoint.first + k == point.first &&
            testPoint.second + k == point.second)
            return 1;
        if (testPoint.first + k == point.first &&
            testPoint.second - k == point.second)
            return 1;
        //===========
    }

    return 2;
}

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    inputarr(x, n);
    inputarr(y, n);
    int ans = INT_MAX;
    pii pointAns;
    for (int i = 0; i < n; i++) {
        // i is the pos to be checked
        int operations = 0;
        pii point = mp(x[i], y[i]);
        for (int j = 0; j < n; j++) {
            if (i != j) {
                pii testPoint = mp(x[j], y[j]);
                operations += numberOfOperations(point, testPoint);
            }
        }
        // ans = min(ans, operations);
        if (operations < ans) {
            ans = operations;
            pointAns = point;
        }
    }
    // cout << ans << " : (" << pointAns.first << "," << pointAns.second << ")"
    //      << endl;
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