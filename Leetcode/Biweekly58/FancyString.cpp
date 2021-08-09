// Author: Ankur Saha
// Linkedin: https://www.linkedin.com/in/ankur-saha/
// Github: https://github.com/Excalibur79

#include <bits/stdc++.h>

#include <string>
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

bool sortComparator(pll a, pll b) {
    if (a.first < b.first) return true;
    if (a.first > b.first) return false;
    return a.second < b.second;
}

void solve(string s) {
    string newString;
    newString.push_back(s[0]);
    int counter = 1;
    char repeatCharacter = s[0];
    for (int i = 1; i < s.length(); i++) {
        char c = s[i];
        if (c == repeatCharacter)
            counter++;
        else
            counter = 1;
        repeatCharacter = s[i];
        if (counter < 3) newString.push_back(s[i]);
    }
    cout << newString << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        string s = "aaabaaaa";
        solve(s);
    }
    return 0;
}