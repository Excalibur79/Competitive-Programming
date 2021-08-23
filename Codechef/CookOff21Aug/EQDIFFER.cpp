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
    int n;
    cin >> n;
    vector<ll> arr;
    unordered_map<ll, ll> frequency;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        arr.pb(x);
        frequency[x]++;
    }
    if (n <= 2)
        cout << 0 << endl;
    else if (frequency.size() == arr.size())
        cout << n - 2 << endl;
    else {
        ll maxOccurence = 0;
        for (auto data : frequency)
            maxOccurence = max(maxOccurence, data.second);
        cout << n - maxOccurence << endl;
    }
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