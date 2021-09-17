// Author: Bihan Chakraborty
// Linkedin: https://www.linkedin.com/in/bihan-chakraborty
// Github: https://github.com/Bihan001

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
const int MOD = 1e9 + 7;
const int INF = 1e18;
#define inputarr(arr, n) \
    for (int i = 0; i < n; i++) cin >> arr[i];
#define printarr(arr, n) \
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';

void solve() {
    int n, k;
    cin >> n >> k;
    vi arr(n);
    inputarr(arr, n);
    vi v(all(arr));
    int zeros = 0, ans = 0;
    for (int it : arr) zeros += (it == 0);
    if (zeros == n) {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                if (arr[n - 1] > 0) v[j]++;
                if (arr[1] > 0) v[j]++;
            } else if (j == n - 1) {
                if (arr[0] > 0) v[j]++;
                if (arr[n - 2] > 0) v[j]++;
            } else {
                if (arr[j - 1] > 0) v[j]++;
                if (arr[j + 1] > 0) v[j]++;
            }
        }
        arr = v;
        zeros = 0;
        for (int it : arr) zeros += (it == 0);
        if (zeros == 0) {
            ans = (k - i) * (n * 2);
            break;
        }
    }
    for (int it : arr) ans += it;
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