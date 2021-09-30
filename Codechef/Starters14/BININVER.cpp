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
    vi arr(n);
    inputarr(arr, n);
    int evenFreq = 0;
    for (auto value : arr) {
        if (value % 2 == 0) evenFreq++;
    }
    if (evenFreq == 0 || evenFreq != n)
        cout << 0 << endl;
    else {
        int counter = 0;
        while (true) {
            int x = 0;
            for (int i = 0; i < n; i++) {
                arr[i] = floor((arr[i] * 1.0) / (2 * 1.0));
                if (arr[i] % 2 == 0)
                    x++;
                else
                    break;
            }
            counter++;
            if (x != n) break;
        }
        cout << counter << endl;
    }
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