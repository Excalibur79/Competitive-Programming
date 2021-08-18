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

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<bool> present(n + 1);

    bool consistent = true;
    while (q--) {
        int query;
        char type;
        cin >> type >> query;
        if (type == '+') {
            if (present[query]) {
                // cout << query << "sdd" << endl;
                consistent = false;
            }
            present[query] = true;
            m--;
            if (m < 0) {
                // cout << query << "sdd" << endl;
                consistent = false;
            }
        } else {
            if (!present[query]) {
                // cout << query << "sdd" << endl;
                consistent = false;
            }
            m++;
        }
    }
    cout << (consistent ? "Consistent" : "Inconsistent") << endl;
}

int main() {
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