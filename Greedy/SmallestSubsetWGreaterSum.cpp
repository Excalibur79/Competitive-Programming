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
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.pb(x);
    }
    sort(arr.begin(), arr.end(), greater<int>());
    for (int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
    }
    int sum = 0, remainingSum;
    for (int i = 0; i < n; i++) {
        sum = arr[i];
        remainingSum = arr[n - 1] - arr[i];
        if (sum > remainingSum) {
            cout << i + 1 << endl;
            break;
        }
    }
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