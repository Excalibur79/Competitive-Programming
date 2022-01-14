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
    vector<int> dragon(3);
    vector<int> sloth(3);
    inputarr(dragon, 3);
    inputarr(sloth, 3);
    int dragonTotal = accumulate(dragon.begin(), dragon.end(), 0);
    int slothTotal = accumulate(sloth.begin(), sloth.end(), 0);
    if (dragonTotal > slothTotal)
        cout << "Dragon" << endl;
    else if (dragonTotal < slothTotal)
        cout << "Sloth" << endl;
    else {
        for (int i = 0; i < 3; i++) {
            if (dragon[i] > sloth[i]) {
                cout << "Dragon" << endl;
                return;
            } else if (dragon[i] < sloth[i]) {
                cout << "Sloth" << endl;
                return;
            }
        }
        cout << "Tie" << endl;
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