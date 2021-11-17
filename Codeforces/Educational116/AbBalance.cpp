// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long int
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

char toggle(char x) { return x == 'a' ? 'b' : 'a'; }

void solve() {
    string s;
    cin >> s;
    int abs = 0, bas = 0;
    int n = s.length();
    for (int i = 1; i < n; i++) {
        if (s[i] == 'b' && s[i - 1] == 'a')
            abs++;
        else if (s[i] == 'a' && s[i - 1] == 'b')
            bas++;
    }
    if (abs == bas)
        cout << s << endl;
    else {
        if (abs > bas) {
            int count = abs - bas;
            for (int i = 1; i < n; i++) {
                if (s[i] == 'b' && s[i - 1] == 'a') {
                    if (s[i + 1] != s[i]) {
                        s[i] = toggle(s[i]);
                    }
                }
            }

        } else if (bas > abs) {
            int count = bas - abs;
            for (int i = 1; i < n; i++) {
                if (s[i] == 'a' && s[i - 1] == 'b') {
                    s[i] = 'b';
                    s[i - 1] = 'a';
                    if (--count) break;
                }
            }
        }
        cout << s << endl;
    }
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