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

bool comp(ll a, ll b) { return a > b; }

void solve() {
    ll m, n;
    cin >> m >> n;
    m--;
    n--;
    vector<ll> horizontalCuts;
    vector<ll> verticalCuts;
    for (ll i = 0; i < m; i++) {
        ll x;
        cin >> x;
        horizontalCuts.pb(x);
    }
    for (ll j = 0; j < n; j++) {
        ll x;
        cin >> x;
        verticalCuts.pb(x);
    }
    sort(horizontalCuts.begin(), horizontalCuts.end(), comp);
    sort(verticalCuts.begin(), verticalCuts.end(), comp);
    ll i = 0, j = 0;  // i for vertical cuts  and j for horizontal cuts
    ll ans = 0, verticalSegments = 1, horizontalSegments = 1;
    while (i < n && j < m) {
        if (verticalCuts[i] > horizontalCuts[j]) {
            ans += verticalCuts[i] * verticalSegments;
            i++;
            horizontalSegments++;
        } else {
            ans += horizontalCuts[j] * horizontalSegments;
            j++;
            verticalSegments++;
        }
    }

    // if array elements from either array is left we must take the entire
    // remaining array

    while (i < n) {
        ans += verticalCuts[i] * verticalSegments;
        i++;
    }
    while (j < m) {
        ans += horizontalCuts[j] * horizontalSegments;
        j++;
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