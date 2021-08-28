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

// Disjoint Set Functions
vector<int> Parent;
vector<int> Rank;

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        Parent.pb(i);
        Rank.pb(0);
    }
}

int Find(int u) {
    if (Parent[u] == u)
        return u;
    else
        return Parent[u] = Find(Parent[u]);
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (Rank[u] < Rank[v]) {
        Parent[u] = v;

    } else if (Rank[v] < Rank[u]) {
        Parent[v] = u;
    } else {
        Parent[u] = v;
        Rank[v]++;
    }
}
//======================

void solve() {
    Parent = {};
    Rank = {};
    ll n;
    cin >> n;
    vector<ll> weights(n + 1);
    makeSet(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> weights[i];
    }

    // for(int i=2;i<=n;i++){
    //     if(weights[i]-weights[i-1]==1)
    //         Union(i,i-1);

    // }

    for (ll i = 1; i <= n; i++) {
        for (ll j = i + 1; j <= n; j++) {
            if ((j - i != weights[j] - weights[i]) && (Find(i) != Find(j))) {
                //   cout << "hola" << j << " " << i << endl;
                Union(i, j);
            }
        }
    }
    unordered_set<ll> totalParents;
    for (ll i = 1; i <= n; i++) {
        totalParents.insert(Find(i));
    }
    // printarr(Parent, Parent.size());
    // cout << endl;
    cout << totalParents.size() << endl;
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