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
    int n;
    cin >> n;
    set<pii> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.insert(mp(x, y));
    }

    int ans = 0;
    for (auto i = points.begin(); i != points.end(); i++) {
        auto j = ++i;
        i--;
        while (j != points.end()) {
            pii pointA = *i;
            pii pointB = *j;
            if (pointB.first > pointA.first && pointB.second > pointA.second) {
                pii pointC = mp(pointB.first, pointA.second);
                pii pointD = mp(pointA.first, pointB.second);
                if (points.find(pointC) != points.end() &&
                    points.find(pointD) != points.end()) {
                    ans++;
                    // cout << "(" << pointA.first << "," << pointA.second << ")
                    // ("
                    //      << pointB.first << "," << pointB.second << ") ("
                    //      << pointC.first << "," << pointC.second << ") ("
                    //      << pointD.first << "," << pointD.second << ")" <<
                    //      endl;
                }
            }
            j++;
        }
    }
    cout << ans << endl;
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