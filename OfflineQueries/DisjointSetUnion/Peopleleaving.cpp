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

// Customized Disjoint Set Functions
vector<int> Parent;
void makeSet(int n) {
    for (int i = 0; i <= n + 1; i++) {
        Parent.pb(i);
    }
}

int Find(int u) {
    if (Parent[u] == u)
        return u;
    else {
        return Parent[u] = Find(Parent[u]);
    }
}

void Union(int left, int right) {
    left = Find(left);
    right = Find(right);
    Parent[left] = right;
}
//================================

void solve() {
    int n, m;
    cin >> n >> m;
    makeSet(n);
    while (m--) {
        int query;
        cin >> query;
        if (query < 0)  // this person will leave from this list eg : -x , x th
                        // indexed person will leave from list
        {
            query *= -1;
            Union(query, query + 1);
        } else {
            int result = Find(query);
            if (result == n + 1)
                cout << -1 << endl;
            else
                cout << result << endl;
        }
    }
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