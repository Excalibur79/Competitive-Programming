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

bool sortComparator(pll a, pll b) {
    if (a.first < b.first) return true;
    if (a.first > b.first) return false;
    return a.second < b.second;
}

pair<ll, ll> Start, End;
map<pair<ll, ll>, ll> Hash;
vector<pair<ll, ll>> arr;
map<pair<ll, ll>, ll> Distance;
map<pair<ll, ll>, ll> visited;

bool isValid(pll node) {
    ll index = lower_bound(arr.begin(), arr.end(), node) - arr.begin();
    if (arr[index].first != node.first) return false;
    if (!visited[node] && (arr[index] == node || Hash[arr[index]] == 2))
        return true;
    return false;
}

bool bfs() {
    visited[Start] = true;
    queue<pair<ll, ll>> q;
    q.push(Start);
    while (!q.empty()) {
        pll node = q.front();
        q.pop();
        vector<pll> neighbours = {{node.first + 1, node.second},
                                  {node.first - 1, node.second},
                                  {node.first, node.second + 1},
                                  {node.first, node.second - 1},
                                  {node.first - 1, node.second - 1},
                                  {node.first - 1, node.second + 1},
                                  {node.first + 1, node.second + 1},
                                  {node.first + 1, node.second - 1}};
        for (auto neighbour : neighbours) {
            if (isValid(neighbour)) {
                visited[neighbour] = true;
                Distance[neighbour] = Distance[node] + 1;
                q.push(neighbour);
                if (neighbour == End) return true;
            }
        }
    }
    return false;
}

void solve() {
    ll x0, y0, x1, y1, n;
    cin >> x0 >> y0 >> x1 >> y1 >> n;
    Start = {x0, y0}, End = {x1, y1};
    while (n--) {
        ll r, a, b;
        cin >> r >> a >> b;
        Hash[mp(r, a)] = 1;
        arr.pb(mp(r, a));
        if (mp(r, a) != mp(r, b)) {
            Hash[mp(r, b)] = 2;
            arr.pb(mp(r, b));
        }
    }
    sort(arr.begin(), arr.end());
    bool ans = bfs();
    if (ans)
        cout << Distance[End] << endl;
    else
        cout << -1 << endl;
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