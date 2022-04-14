// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>
#include <ctype.h>

#include <string>
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

string getString(char x) {
    string s(1, x);
    return s;
}

bool solve() {
    string s;
    cin >> s;
    vector<int> prefix(s.size(), 0);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') prefix[i] = 1;
    }
    for (int i = 1; i < s.size(); i++) {
        prefix[i] += prefix[i - 1];
    }

    bool valid = false;

    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            if (isdigit(s[i]) && isdigit(s[j])) {
                if (stoi(getString(s[i])) + stoi(getString(s[j])) == 10) {
                    valid = true;
                    int x = prefix[j] - (i - 1 >= 0 ? prefix[i - 1] : 0);
                    // cout << s[i] << " " << s[j] << " " << x << endl;
                    if (x != 3) return false;
                }
            }
        }
    }
    return valid;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}