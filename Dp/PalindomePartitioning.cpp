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

bool isPalindrome(string &s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int palindromePartition(string &s, int i, int j) {
    if (i >= j) return 0;
    if (isPalindrome(s, i, j)) return 0;
    int minn = INT_MAX, temp;
    for (int k = i; k < j; k++) {
        temp =
            palindromePartition(s, i, k) + palindromePartition(s, k + 1, j) + 1;
        minn = min(minn, temp);
    }
    return minn;
}

void solve() {
    string s;
    cin >> s;
    cout << palindromePartition(s, 0, s.size() - 1) << endl;
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