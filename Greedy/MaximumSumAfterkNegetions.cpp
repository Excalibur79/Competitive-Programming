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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> arr;
    int posCount = 0;
    int negCount = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        arr.pb(x);
        if (x < 0)
            negCount++;
        else
            posCount++;
    }

    sort(arr.begin(), arr.end());
    if (posCount == n) {
        if (k % 2 != 0) {
            arr[0] *= -1;
        }
    } else {
        if (k <= negCount) {
            for (int i = 0; i < k; i++) {
                arr[i] *= -1;
            }
        } else if (k > negCount) {
            for (int i = 0; i < negCount; i++) {
                arr[i] *= -1;
            }
            sort(arr.begin(), arr.end());
            printarr(arr, n);
            if ((negCount - k) % 2 != 0) arr[0] *= -1;
        }
    }
    int sum = 0;
    for (auto value : arr) sum += value;
    cout << sum;
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