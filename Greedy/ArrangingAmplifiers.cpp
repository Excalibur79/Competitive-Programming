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
    vector<int> amplifiers(n);
    inputarr(amplifiers, n);
    int ones = 0;
    for (auto value : amplifiers) {
        if (value == 1) ones++;
    }
    sort(amplifiers.begin(), amplifiers.end(), greater<int>());
    for (int i = 0; i < ones; i++) cout << 1 << " ";
    if (n - ones == 2 && amplifiers[0] == 3 && amplifiers[1] == 2)
        cout << "2 3" << endl;
    else {
        for (int i = 0; i < n - ones; i++) {
            int value = amplifiers[i];
            cout << value << " ";
        }
        cout << endl;
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