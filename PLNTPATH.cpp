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
    int n, k, s;
    cin >> n >> k >> s;
    map<int, vector<int>> alliances;
    map<int, vector<pii>> graph;
    for (int i = 0; i < n; i++) graph[i] = {};

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        alliances[x - 1].pb(i);
    }
    for (auto alliance : alliances) {
        vector<int> data = alliance.second;
        for (int i = 0; i < data.size(); i++) {
            for (int j = i + 1; j < data.size(); j++) {
                graph[data[i]].pb(mp(0, data[j]));
                graph[data[j]].pb(mp(0, data[i]));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int wt;
            cin >> wt;
            if (wt != -1 && wt != 0) {
                vector<int> data = alliances[j];
                for (auto node : data) {
                    graph[i].pb(mp(wt, node));
                    graph[node].pb(mp(wt, i));
                }
            }
        }
    }

    for (auto data : graph) {
        int node = data.first;
        vector<pii> neighbours = data.second;
        cout << node << "==>";
        for (auto neighbour : neighbours)
            cout << "(" << neighbour.first << " " << neighbour.second << "), ";
        cout << endl;
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