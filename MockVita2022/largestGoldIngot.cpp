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

int calculateCuboid(vector<int> &ignots, int requirement) {
    int j = 0;
    int curData = 0;
    int maxVal = 0;
    int n = ignots.size();
    while (j < n) {
        if (ignots[j] >= requirement) {
            curData += requirement % MOD;
            maxVal = max(maxVal, curData);
            j++;
        } else {
            curData = 0;
            j++;
        }
    }
    return maxVal;
}

void solve() {
    int g, b, h;
    cin >> g >> b >> h;
    vector<int> ingots(g);
    set<int> orderedIngots;
    for (int i = 0; i < g; i++) {
        int x;
        cin >> x;
        orderedIngots.insert(x);
        ingots.pb(x);
    }
    int cuboid = 0;
    for (int data : orderedIngots) {
        //  cout << data << " >> " << calculateCuboid(ingots, data) << endl;
        cuboid = max(cuboid, calculateCuboid(ingots, data));
    }
    cout << (b * h * (accumulate(ingots.begin(), ingots.end(), 0) - cuboid)) %
                MOD;
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