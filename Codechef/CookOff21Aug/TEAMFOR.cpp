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

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int ans = 0;
    unordered_set<int> omit;
    vector<pair<char, char>> arr;
    for (int i = 0; i < n; i++) {
        arr.pb(mp(s[i], t[i]));
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        if (omit.find(i) != omit.end()) continue;
        pair<char, char> student1 = arr[i];
        for (int j = i + 1; j < n; j++) {
            if (omit.find(j) != omit.end()) continue;
            pair<char, char> student2 = arr[j];
            bool progValidated = false;
            bool engValidated = false;
            if (student1.first == '1' || student2.first == '1')
                progValidated = true;
            if (student1.second == '1' || student2.second == '1')
                engValidated = true;
            if (engValidated && progValidated) {
                ans++;
                omit.insert(i);
                omit.insert(j);
                // cout << i << " " << j << " " << ans << endl;
                // for (auto data : omit) cout << data << " ";
                // cout << endl;
                break;
            }
        }
    }
    // for (auto data : arr) cout << data.first << " " << data.second << endl;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q = 1;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}