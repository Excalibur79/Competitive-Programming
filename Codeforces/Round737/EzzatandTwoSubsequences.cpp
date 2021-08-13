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

void solve() {
    int n;
    cin >> n;
    vector<ll> arr;
    ll totalSum = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        ;
        cin >> x;
        arr.pb(x);
        totalSum += x;
    }
    sort(arr.begin(), arr.end());
    // prefix array
    vector<ll> prefixArr;
    ll sum = 0;
    for (auto value : arr) {
        sum += value;
        prefixArr.pb(sum);
    }
    //============
    double ans = INT_MIN;
    for (int i = 0; i < n - 1; i++) {
        ll leftSum = prefixArr[i];
        ll rightSum = prefixArr[n - 1] - prefixArr[i];
        double leftAns = (leftSum * 1.0) / ((i + 1) * 1.0);
        double rightAns = (rightSum * 1.0) / ((n - 1 - i) * 1.0);
        ans = max(ans, rightAns + leftAns);
    }
    cout << fixed << setprecision(9) << ans << endl;
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