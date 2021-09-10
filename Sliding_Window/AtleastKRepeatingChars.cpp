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
    string s;
    int k;
    cin >> s >> k;
    int maxUnique = INT_MIN;
    unordered_map<char, int> occurences;
    for (char c : s) {
        occurences[c]++;
        maxUnique = max(occurences[c], maxUnique);
    }
    cout << maxUnique << " sdasd" << endl;
    int n = s.size();
    int ans = 0;
    for (int windowUnique = 1; windowUnique <= maxUnique; windowUnique++) {
        // demanding k unique characters in a window
        int i = 0, j = 0;
        unordered_map<char, int> windowOccurences;
        int countAtleastK = 0;
        while (j < n) {
            windowOccurences[s[j]]++;
            if (windowOccurences[s[j]] == k) countAtleastK++;

            if (windowOccurences.size() < windowUnique) {
                j++;
            } else if (windowOccurences.size() > windowUnique) {
                while (windowOccurences.size() > windowUnique) {
                    windowOccurences[s[i]]--;
                    if (windowOccurences[s[i]] == 0) {
                        windowOccurences.erase(s[i]);
                        countAtleastK--;
                    }

                    i++;
                }
                j++;
            } else if (windowOccurences.size() == windowUnique &&
                       windowOccurences.size() == k) {
                cout << i << " " << j << " " << windowUnique << endl;
                ans = max(ans, j - i + 1);
                j++;
            }
        }
    }
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