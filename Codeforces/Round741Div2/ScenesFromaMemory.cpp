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

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve() {
    ll k;
    string s;
    cin >> k >> s;
    ll length = s.size();

    for (char c : s) {
        if (c != '2' && c != '3' && c != '5' && c != '7') {
            cout << 1 << endl << c << endl;
            return;
        }
    }

    // sort(n.begin(), n.end());
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            int n;
            n = s[i] - '0';
            n *= 10;
            n += (s[j] - '0');
            if (!isPrime(n)) {
                cout << 2 << endl << n << endl;
                return;
            }
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