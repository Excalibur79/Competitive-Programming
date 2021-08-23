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
    int onlyProg = 0, onlyEng = 0, both = 0, worthless = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && t[i] == '1')
            both++;
        else if (s[i] == '1')
            onlyProg++;
        else if (t[i] == '1')
            onlyEng++;
        else
            worthless++;
    }
    int minn = min(onlyProg, onlyEng);
    onlyProg = onlyProg - minn;
    onlyEng = onlyEng - minn;
    ans += minn;

    minn = min(both, onlyProg + onlyEng + worthless);
    ans += minn;
    both = both - minn;

    ans = ans + both / 2;
    cout << ans << endl;
}

int main() {
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