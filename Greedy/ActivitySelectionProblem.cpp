// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_backs
#define mp make_pair
const int MOD = 1e9 + 7;
const ll INF = 1e18;
#define inputarr(arr, n) \
    for (ll i = 0; i < n; i++) cin >> arr[i];
#define printarr(arr, n) \
    for (ll i = 0; i < n; i++) cout << arr[i] << ' ';

bool comparator(pii a, pii b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void solve() {
    // int n;
    // cin >> n;
    vector<int> start = {10, 12, 20};
    vector<int> end = {20, 25, 30};
    vector<pii> slots;
    for (int i = 0; i < end.size(); i++) {
        slots.pb(mp(start[i], end[i]));
    }
    sort(slots.begin(), slots.end(), comparator);
    // for (auto data : slots) {
    //     cout << data.first << " " << data.second << endl;
    // }
    int ans = 1;
    int i = 0, j = 1;
    while (j < start.size()) {
        pii firstPair = slots[i];
        pii secondPair = slots[j];
        if (firstPair.second < secondPair.first) {
            ans++;
            i = j;
        }
        j++;
    }
    cout << ans << endl;
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