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
    for (ll i = 0; i < n; i++) cout << arr[i] << " ";

vector<string> SplitString(string s, char delimiter) {
    vector<string> v;
    string temp = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == delimiter) {
            v.push_back(temp);
            temp = "";
        } else {
            temp.push_back(s[i]);
        }
    }
    v.push_back(temp);
    return v;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<vector<string>, vector<string>>> busData;
    for (int i = 0; i < n; i++) {
        string s;
        geline(cin, s);
        vector<string> firstSplit = SplitString(s, '|');
        vector<string> boardingPassengers = SplitString(firstSplit[0], ' ');
        vector<string> alightingPassengers = SplitString(firstSplit[1], ' ');
        busData.pb(mp(boardingPassengers, alightingPassengers));
    
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