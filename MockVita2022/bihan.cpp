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
    int n, b, h;
    cin >> n;
    cin >> b >> h;
    vi arr(n);
    inputarr(arr, n);
    int oldvol = 0;
    for (int i = 0; i < n; i++) {
        oldvol += arr[i] * b * h;
    };
    vi copy = arr;
    sort(all(copy));
    int maxcnt = 0, maxv = 0;
    for (int i = 0; i < n; i++) {
        int len = copy[i];
        int cnt = 0, currv = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] >= len) {
                cnt++;
                currv += len * b * h;
            } else {
                cnt = 0;
                currv = 0;
            }
            if (currv > maxv) {
                maxv = currv;
                maxcnt = cnt;
            }
        }
    }
    int newvol = maxv;
    cout << oldvol - newvol << endl;
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
