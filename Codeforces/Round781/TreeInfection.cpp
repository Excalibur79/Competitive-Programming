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
    vector<vector<int>> tree(n + 1);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        tree[x - 1].pb(i);
    }
    vector<int> childs;
    for (auto data : tree) {
        if (data.size() > 0) childs.push_back(data.size());
    }
    int ans = 0;
    int rootTaken = false;
    while (childs.size() > 0) {
        if (childs.size() == 1 && childs[0] == 2) {
            ans += 1;
            break;
        }
        ans += childs.size();
        vector<int> newChilds;
        for (int i = 0; i < childs.size(); i++) {
            if (childs[i] - childs.size() > 0)
                newChilds.push_back(childs[i] - childs.size());
        }

        childs = newChilds;
        if (!rootTaken) {
            rootTaken = true;
            childs.push_back(1);
        }
    }
    cout << ans << endl;
}

int32_t main() {
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