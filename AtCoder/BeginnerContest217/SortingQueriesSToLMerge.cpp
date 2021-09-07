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
    int q;
    cin >> q;
    multiset<int> sortedSt, curSt;
    list<int> cur;

    while (q--) {
        int type;
        cin >> type;
        switch (type) {
            case 1:
                int x;
                cin >> x;
                cur.push_back(x);
                curSt.insert(x);
                break;
            case 2:
                if (sortedSt.empty()) {
                    cout << cur.front() << endl;
                    curSt.erase(curSt.find(cur.front()));
                    cur.pop_front();
                } else {
                    cout << *(sortedSt.begin()) << endl;
                    sortedSt.erase(sortedSt.begin());
                }
                break;
            case 3:
                cur.clear();
                if (sortedSt.size() < curSt.size()) swap(sortedSt, curSt);
                for (auto value : curSt) sortedSt.insert(value);
                curSt.clear();
                break;
        }
    }
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