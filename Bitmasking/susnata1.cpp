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

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    unordered_map<char, int> m;
    for (char c : s1) m[c]++;
    for (char c : s2) m[c]++;
    int i = s1.length() - 1;
    int j = 0;
    int steps = 0;
    while (m['0'] != m['1']) {
        if (m['1'] > m['0']) {
            if (s1[i] == '1')
                i--;
            else if (s2[j] == '1')
                j++;
            m['1']--;
        } else {
            if (s1[i] == '0')
                i--;
            else if (s2[j] == '0')
                j++;
            m['0']--;
        }
        steps++;
    }
    cout << i << " " << j << endl;
    cout << steps << endl;
}

int32_t main() {
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