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

int memoize[1001][1001][4];

int dieHard(int h, int a, int domain) {
    if (h <= 0 || a <= 0) return 0;
    if (memoize[h][a][domain] != -1) return memoize[h][a][domain];
    if (domain == 1)
        return memoize[h][a][domain] = max((1 + dieHard(h - 5, a - 10, 2)),
                                           (1 + dieHard(h - 20, a + 5, 3)));
    else if (domain == 2)
        return memoize[h][a][domain] = max((1 + dieHard(h + 3, a + 2, 1)),
                                           (1 + dieHard(h - 20, a + 5, 3)));
    else if (domain == 3)
        return memoize[h][a][domain] = max((1 + dieHard(h + 3, a + 2, 1)),
                                           (1 + dieHard(h - 5, a - 10, 2)));
}

void solve() {
    int h, a;
    cin >> h >> a;
    memset(memoize, -1, sizeof(memoize));
    int ans = max(max(dieHard(h + 3, a + 2, 1), dieHard(h - 5, a - 10, 2)),
                  dieHard(h - 20, a + 5, 3));
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