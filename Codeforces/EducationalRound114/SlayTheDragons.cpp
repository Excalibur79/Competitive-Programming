#include <bits/stdc++.h>
typedef long long int ll;
const unsigned int MOD = 1000000007;

using namespace std;

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());
    ll m;
    cin >> m;
    for (ll i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        ll coins = 0;
        ll in = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if (in == 0) {
            if (y > (sum - arr[in])) coins += (y - (sum - arr[in]));
        } else if (in != n) {
            ll a = 0, b = 0;
            if (arr[in] < x) a += x - arr[in];
            if (y > (sum - arr[in])) a += (y - (sum - arr[in]));

            if (arr[in - 1] < x) b += x - arr[in - 1];
            if (y > (sum - arr[in - 1])) b += (y - (sum - arr[in - 1]));
            coins = min(a, b);
        } else {
            ll b = 0;
            if (arr[in - 1] < x) b += x - arr[in - 1];
            if (y > (sum - arr[in - 1])) b += (y - (sum - arr[in - 1]));
            coins = b;
        }
        cout << coins << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    for (int tt = 0; tt < t; tt++) {
        solve();
    }

    return 0;
}