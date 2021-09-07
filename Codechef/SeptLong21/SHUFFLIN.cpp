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
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    stack<int> odds;
    stack<int> evens;
    for (int i = 1; i <= n; i++) {
        if ((i + arr[i]) % 2 == 0) {
            if (arr[i] % 2 != 0) {
                if (!evens.empty()) {
                    int index = evens.top();
                    evens.pop();
                    swap(arr[index], arr[i]);
                } else {
                    odds.push(i);
                }
            } else {
                if (!odds.empty()) {
                    int index = odds.top();
                    odds.pop();
                    swap(arr[index], arr[i]);
                } else
                    evens.push(i);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += (i + arr[i]) % 2;
    cout << ans << endl;
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