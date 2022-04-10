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
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;

    char curChar = '.';
    map<char, queue<int>> hash;
    for (int i = 0; i < n; i++) {
        hash[s1[i]].push(i);
        if (curChar == '.' && s1[i] != '?') curChar = s1[i];
    }
    int leftIdx = -1;
    int lengthCheck = 0;
    for (char c : s2) {
        if (hash.find(c) != hash.end() && hash[c].size() != 0 &&
            hash[c].front() > leftIdx) {
            leftIdx = hash[c].front();
            hash[c].pop();
            lengthCheck++;
        } else
            break;
    }
    if (lengthCheck == m) {
        cout << -1 << endl;
        return;
    }

    if (curChar == '.') {
        curChar = s2[0] == 'a' ? 'b' : 'a';
        for (int i = 0; i < n; i++) {
            s1[i] = curChar;
        }

    } else {
        for (int i = 0; i < n; i++) {
            if (s1[i] != '?') curChar = s1[i];
            s1[i] = curChar;
        }
    }

    cout << s1 << endl;
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