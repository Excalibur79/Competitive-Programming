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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> arr;
    vector<ll> sortedArr;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        arr.pb(x);
        sortedArr.pb(x);
    }
    sort(sortedArr.begin(), sortedArr.end());
    unordered_map<ll, int> hash;
    for (int i = 0; i < n; i++) {
        hash[sortedArr[i]] = i;
    }
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (hash[arr[i]] > 0 && i > 0 &&
            sortedArr[hash[arr[i]] - 1] == arr[i - 1])
            continue;
        else
            counter++;
    }
    if (counter <= k)
        cout << "Yes" << counter << endl;
    else
        cout << "No" << counter << endl;
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