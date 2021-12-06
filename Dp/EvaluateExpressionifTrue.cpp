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

int evaluate(string &s, int i, int j, bool isTrue) {
    if (i == j) {
        if (isTrue)
            return s[i] == 'T' ? 1 : 0;
        else
            return s[i] == 'F' ? 1 : 0;
    }
    if (i > j) return 0;
    int temp = 0;
    for (int k = i + 1; k < j; k += 2) {
        int leftTrue = evaluate(s, i, k - 1, true);
        int rightTrue = evaluate(s, k + 1, j, true);
        int leftFalse = evaluate(s, i, k - 1, false);
        int rightFalse = evaluate(s, k + 1, j, false);
        if (s[k] == '|') {
            if (isTrue)
                temp += ((leftTrue * rightTrue) + (leftTrue * rightFalse) +
                         (leftFalse * rightTrue));
            else
                temp += (leftFalse * rightFalse);
        }
        if (s[k] == '&') {
            if (isTrue)
                temp += leftTrue * rightTrue;
            else
                temp += ((leftFalse * rightTrue) + (leftTrue * rightFalse) +
                         (leftFalse * rightFalse));
        }
        if (s[k] == '^') {
            if (isTrue)
                temp += ((leftFalse * rightTrue) + (leftTrue * rightFalse));
            else
                temp += ((leftTrue * rightTrue) + (leftFalse * rightFalse));
        }
    }
    return temp;
}

void solve() {
    string s;
    cin >> s;
    int ans = evaluate(s, 0, s.size() - 1, true);
    cout << ans << endl;
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