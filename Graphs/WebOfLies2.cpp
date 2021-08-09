// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
using namespace std;

#define ll long long
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

int ans;

bool sortComparator(pll a, pll b) {
    if (a.first < b.first) return true;
    if (a.first > b.first) return false;
    return a.second < b.second;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1, 0);
    ans = n;
    while (m--) {
        int u, v;
        cin >> u >> v;
        arr[min(u, v)]++;
        if (arr[min(u, v)] == 1) ans--;
    }
    int copyAns = ans;
    vector<int> copyArr = arr;
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        switch (type) {
            case 1:
                int x, y;
                cin >> x >> y;
                arr[min(x, y)]++;
                if (arr[min(x, y)] == 1) ans--;
                break;
            case 2:
                cin >> x >> y;
                arr[min(x, y)]--;
                if (arr[min(x, y)] == 0) ans++;
                break;
            case 3:
                cout << ans << endl;

                break;
            default:
                break;
        }
    }
}

int main() {
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