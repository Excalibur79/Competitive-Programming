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

void solve(int testCase) {
    int n;
    cin >> n;
    set<int> army1;
    set<int> army2;
    while (n--) {
        int a, b;
        cin >> a >> b;

        bool ainArmy1 = army1.find(a) != army1.end();
        bool ainArmy2 = army2.find(a) != army2.end();
        bool binArmy1 = army1.find(b) != army1.end();
        bool binArmy2 = army2.find(b) != army2.end();

        if (ainArmy1 && binArmy1) {
            army1.erase(b);
            army2.insert(b);
            continue;
        } else if (ainArmy2 && binArmy2) {
            army2.erase(b);
            army1.insert(b);
            continue;
        }

        if ((ainArmy1 || ainArmy2) && (binArmy1 || binArmy2)) continue;
        if (!ainArmy1 && !ainArmy2 && !binArmy1 && !binArmy2) {
            army1.insert(a);
            army2.insert(b);
        } else {  // one guy is already in a set
                  // cout << "asda " << a << " " << b << endl;
            if (ainArmy1)
                army2.insert(b);
            else if (ainArmy2)
                army1.insert(b);
            else if (binArmy1)
                army2.insert(a);
            else if (binArmy2)
                army1.insert(a);
        }
        for (auto value : army1) cout << value << " ";
        cout << endl;
        for (auto value : army2) cout << value << " ";
        cout << endl;
    }
    // for (auto value : army1) cout << value << " ";
    // cout << endl;
    // for (auto value : army2) cout << value << " ";
    // cout << endl;
    cout << "Case " << testCase << ": " << max(army1.size(), army2.size())
         << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    int i = 0;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}