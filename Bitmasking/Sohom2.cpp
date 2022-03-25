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
    vector<int> arr(n);
    vector<pair<int, int>> pArr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
        pArr.push_back(make_pair(x, i));
    }
    sort(pArr.begin(), pArr.end());
    int a = pArr[n - 3].second;
    int b = pArr[n - 2].second;
    int c = pArr[n - 1].second;
    int d = pArr[0].second;
    int e = pArr[1].second;
    int f = pArr[2].second;

    int val2 = pArr[0].first * pArr[1].first;
    int val1 = pArr[b].first * pArr[c].first;
    for (int i = 0; i < n; i++) {
        if (i != b && i != c && i != d && i != e)
            cout << max(val1, val2) << endl;
        else {
            if (i == d)
                cout << max(arr[e] * arr[f], val1) << endl;
            else if (i == e)
                cout << max(arr[d] * arr[f], val1) << endl;
            else if (i == b)
                cout << max(arr[a] * arr[c], val2) << endl;
            else if (i == c)
                cout << max(arr[a] * arr[b], val2) << endl;
        }
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