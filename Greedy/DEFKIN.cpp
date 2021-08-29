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

string decimalToBinary(ll n, ll fix) {
    string bin = "";
    while (n) {
        bin += to_string(n % 2);
        n /= 2;
    }
    reverse(bin.begin(), bin.end());
    // Make of Size fix
    int cur = bin.size();
    string res = string(fix - cur, '0');
    res += bin;
    return res;
}

void solve() {
    int w, h, n;
    cin >> w >> h >> n;
    vector<pii> towers;
    // fake towers
    towers.pb(mp(0, 0));
    towers.pb(mp(h, w));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        towers.pb(mp(y, x));
    }
    sort(towers.begin(), towers.end());
    for (auto data : towers) cout << data.first << " " << data.second << endl;
    priority_queue<int> width;
    priority_queue<int> height;
    for (int i = 1; i < n; i++) {
        width.push(towers[i].first - towers[i - 1].first);
        height.push(towers[i].second - towers[i - 1].second);
    }
    cout << width.top() * height.top() << endl;
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