// Author: Bihan Chakraborty
// Linkedin: https://www.linkedin.com/in/bihan-chakraborty
// Github: https://github.com/Bihan001

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
const int MOD = 1e9 + 7;
const ll INF = 1e18;
#define inputarr(arr, n) \
    for (ll i = 0; i < n; i++) cin >> arr[i];
#define printarr(arr, n) \
    for (ll i = 0; i < n; i++) cout << arr[i] << ' ';

map<string, ll> dp;

ll recurse(ll i, ll h, ll a, vector<pll> &info, vector<vll> &graph) {
    h += info[i].first, a += info[i].second;
    if (h <= 0 || a <= 0) return 0;
    string s = to_string(i) + '#' + to_string(h) + '#' + to_string(a);
    if (dp.find(s) != dp.end()) return dp[s];
    ll ans = 0;
    for (ll next : graph[i]) {
        ans = max(ans, 1 + recurse(next, h, a, info, graph));
    }
    return dp[s] = ans;
}

void solve() {
    ll h, a;
    cin >> h >> a;
    vector<pll> info(3);
    info[0] = mp(3, 2), info[1] = mp(-5, -10), info[2] = mp(-20, 5);
    vector<vll> graph(3);
    graph[0].pb(1);
    graph[0].pb(2);
    graph[1].pb(0);
    graph[1].pb(2);
    graph[2].pb(0);
    graph[2].pb(1);
    dp.clear();
    ll ans = 0;
    for (int i = 0; i <= 2; i++) {
        ans = max(ans, recurse(i, h, a, info, graph));
    }
    cout << ans << endl;
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