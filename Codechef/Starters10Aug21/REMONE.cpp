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

bool isValid(auto &a, auto &b, ll x) {
    ll oneOmmited = false;
    for (auto value : a) {
        bool found = binary_search(b.begin(), b.end(), value + x);
        //  cout << x << " finding : " << value + x << " :" << found << " ";
        if (!found) {
            if (!oneOmmited) {
                oneOmmited = true;
                continue;
            } else {
                return false;
            }
        }
    }
    // cout << endl;
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n - 1);
    ll al = INT_MAX;
    ll ah = INT_MIN;
    ll bl = INT_MAX;
    ll bh = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        al = min(al, a[i]);
        ah = max(ah, a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
        bl = min(bl, b[i]);
        bh = max(bh, b[i]);
    }
    ll h = max(bh - al, bl - ah);
    ll l = min(bl - al, bh - ah);
    // cout << l << " " << h << endl;
    sort(b.begin(), b.end());
    for (ll i = max(l, (ll)1); i <= max(h, (ll)1); i++) {
        if (isValid(a, b, i)) {
            cout << i << endl;
            break;
        }
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