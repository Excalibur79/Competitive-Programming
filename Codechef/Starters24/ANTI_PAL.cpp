// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
using namespace std;

#define ll long long
// #define int long long int
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

string getString(char x) {
    string s(1, x);
    return s;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n % 2 != 0) {
        cout << "NO" << endl;
        return;
    }
    map<char, int> hash;
    for (char c : s) {
        hash[c]++;
        if (hash[c] > n / 2) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    char ans[n];
    int k = 0;
    for (auto data : hash) {
        for (int i = 0; i < data.second; i++) {
            ans[k++] = data.first;
        }
    }
    reverse(ans, ans + n / 2);
    for (char data : ans) cout << data;
    cout << endl;
}

int32_t main() {
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