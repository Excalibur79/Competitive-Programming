// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define vll vector<ll>
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define inputarr(arr, n) \
    for (ll i = 0; i < n; i++) cin >> arr[i];
#define prllarr(arr, n) \
    for (ll i = 0; i < n; i++) cout << arr[i] << ' ';

string decimalToBinary(ll n, ll fix) {
    string bin = "";
    while (n) {
        bin += to_string(n % 2);
        n /= 2;
    }
    reverse(bin.begin(), bin.end());
    // Make of Size fix
    ll cur = bin.size();
    string res = string(fix - cur, '0');
    res += bin;
    return res;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr;
    ll maxValue = INT_MIN;
    vector<ll> maxValueIndexes;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        arr.pb(x);
        maxValue = max(maxValue, x);
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ll value = arr[i];
        if (value == maxValue) maxValueIndexes.pb(i);
    }
    for (auto value : maxValueIndexes) {
        // cout << value << "asd" << endl;
        if (value >= k - 1) {
            ans = ans + (n - value);
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}